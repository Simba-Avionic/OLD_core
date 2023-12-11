import logging

from .validator import SimBaConfigsValidator
from utils.base_class import BaseClass


# The `Service` class is a subclass of `BaseClass` that loads data from a file, validates the schema,
# and provides methods to retrieve service information by name, ID, method name, and interface name.
class Service(BaseClass):
    def __init__(self,filepath:str):
        self.load_data(filepath)
        self.data=self.data["services"]

        if not SimBaConfigsValidator().validate_services(filepath):
            logging.warning("invalid Service schema")

    def get_event_id(self,service_name,event_name):
        for service in self.data:
            if service.get("name",None)==service_name:
                for event in service.get("events",[]):
                    if event.get("name",None)==event_name:
                        return event.get("event_id",None)
                return None

    def get_by_name(self,name:str)->dict|None:
        for s in self.data:
            if s.get("name",None)==name:
                return s
        return None
    def get_by_id(self,ID:int)->dict|None:
        for s in self.data:
            if s["service_id"]==ID:
                return s
        return None
    def get_method_id_by_name(self,name:str)->int|None:
        for s in self.data:
            for m in s.get("methods",[]):
                if name==m.get("name",None):
                    return m.get("method_id",None)
    def get_interface_name_by_service_name(self,service_name:str)->str|None:
        for s in self.data:
            if s["name"]==service_name:
                return s["interface"]
        return None

    def get_subscribers(self,event_name):
        services_id=[]
        for service in self.data:
            for event in service.get("req_qvents",[]):
                if event==event_name:
                    service_id=service.get("name",None)
                    if service_id not in services_id and service_id!=None:
                        services_id.append(service_id)

        logging.info(f"subskrybenci event_id:{event_name} to {services_id}")
        return services_id