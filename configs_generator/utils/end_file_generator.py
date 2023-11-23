
import json
import logging
from utils.router import Router
from utils.service import Service
from utils.interface import Interface



class EndFileGenerator:
    """
    The EndFileGenerator class is used to generate end files.
    """
    router:Router
    service:Service
    interface:Interface
    file_path:str
    service_name:str

    def _generate_interface(self,interface_name:str):
        """
            The function `_generate_interface` generates an interface dictionary with the given interface name.
            
            @param interface_name The `interface_name` parameter is a string that represents the name of the
            interface.
            
            @return a dictionary with three keys: "ip", "ipc", and "port". The values for "ip" and "port" are
            empty strings and 0 respectively. The value for "ipc" is obtained from the "interface" object by
            calling the "get_by_interface_name" method with the input parameter "interface_name".
            """
        out={
            "ip":"",
            "ipc":self.interface.get_by_interface_name(interface_name)["ipc"],
            "port":0
        }
        logging.info(f"_generate_interface {out}")
        return out

    def _generate_db(self,req_services:list,own_interface_name:str)-> dict | None:
        """
        The function `_generate_db` generates a database dictionary based on a list of requested services
        and an interface name.
        
        @param req_services A list of required services, where each element is a string representing an
        endpoint in the format "service_name/method_name".
        @param own_interface_name The `own_interface_name` parameter is a string that represents the name of
        the interface of the current service.
        
        @return a dictionary object `db` or `None`.
        """
        db={}
        for endpoint in req_services:
            remote_service_name=endpoint.split("/")[0]
            remote_method_name=endpoint.split("/")[1]
            remote_service_id=self.service.get_by_name(remote_service_name)["service_id"]
            remote_service_interface_name=self.service.get_by_name(remote_service_name)["interface"]
            remote_service_interface=self.interface.get_by_interface_name(remote_service_interface_name)
            remote_method_id=self.service.get_method_id_by_name(remote_method_name)
            if self.router.service_is_in_the_same_router(own_interface_name,remote_service_interface_name):
                remote_service_interface["port"]=0
                remote_service_interface["ip"]=""
            else:
                remote_service_interface["ipc"]=""
            db[endpoint]={
                "service_id":remote_service_id,
                "method_id":remote_method_id,
                "interface":remote_service_interface
            }
        return db

    def __init__(self,service_name:str,path:str):
        self.router=Router(f"{path}routers.json")
        self.interface=Interface(f"{path}interface.json")
        self.service=Service(f"{path}services.json")
        self.service_name=service_name
        if self.service.get_by_name(self.service_name) is None:
            logging.fatal(f"Service with name {self.service_name} dont exist")
    
    def save_to_file(self,path,data):
        """
        The `save_to_file` function saves data to a JSON file at the specified path.
        
        @param path The `path` parameter is a string that represents the directory path where the file will
        be saved. It should be the absolute or relative path to the directory where you want to save the
        file.
        @param data The `data` parameter is the data that you want to save to a file. It can be any valid
        JSON data, such as a dictionary, list, or string.
        """
        with open(f"{path}/out.json","w") as file:
            json.dump(data,file,indent=4)


    def generate_output_json(self):
        """
        The function `generate_output_json` generates an output JSON dictionary based on the properties of a
        given service.
        
        @return a dictionary object named `out_dict`.
        """
        out_dict = {}
        work_service = self.service.get_by_name(self.service_name)

        if work_service is None:
            print(f"Service with name {self.service_name} does not exist")
            return out_dict

        interface_name = work_service.get("interface", "")
        out_dict["name"] = work_service.get("name", "")
        out_dict["service_id"] = work_service.get("service_id", "")
        out_dict["interface"] = self._generate_interface(interface_name)

        try:
            out_dict["methods"] = work_service["methods"]
        except KeyError:
            print("Service does not have any methods")

        try:
            req_services = work_service.get("req_services", [])
            out_dict["db"] = self._generate_db(req_services, interface_name)
        except KeyError:
            print("Service does not have any req service")

        try:
            out_dict["conf"] = work_service["conf"]
        except KeyError:
            print("Service does not have configs")

        return out_dict
