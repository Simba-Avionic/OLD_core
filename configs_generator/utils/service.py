import logging

from .validator import SimBaConfigsValidator
from utils.base_class import BaseClass


# The `Service` class is a subclass of `BaseClass` that loads data from a file, validates the schema,
# and provides methods to retrieve service information by name, ID, method name, and interface name.
class Service(BaseClass):
    def __init__(self,filepath:str):
        """
        The above function initializes an object with a given filepath, loads data from the file, and
        validates the data against a schema.
        
        :param filepath: The `filepath` parameter is a string that represents the path to a file. It is used
        to load data from the specified file
        :type filepath: str
        """
        self.load_data(filepath)
        self.data=self.data["services"]

        if not SimBaConfigsValidator().validate_services(filepath):
            logging.warning("invalid Service schema")

    def get_by_name(self,name:str)->dict|None:
        """
        The `get_by_name` function takes a name as input and returns the dictionary object with a matching
        name from the `data` list, or `None` if no match is found.
        
        :param name: A string representing the name of the item you want to retrieve from the data
        :type name: str
        :return: a dictionary if a match is found for the given name in the data list. If no match is found,
        it returns None.
        """
        for s in self.data:
            if s["name"]==name:
                return s
        return None
    def get_by_id(self,ID:int)->dict|None:
        """
        The `get_by_id` function takes an ID as input and returns the dictionary with the matching
        service_id, or None if no match is found.
        
        :param ID: The parameter `ID` is an integer that represents the service ID
        :type ID: int
        :return: a dictionary if a service with the specified ID is found in the data. If no service is
        found with the specified ID, it returns None.
        """
        for s in self.data:
            if s["service_id"]==ID:
                return s
        return None
    def get_method_id_by_name(self,name:str)->int|None:
        """
        The function `get_method_id_by_name` returns the method ID of a given method name if it exists in
        the data, otherwise it returns None.
        
        :param name: The `name` parameter is a string that represents the name of a method
        :type name: str
        :return: The method is returning an integer value representing the method ID if a method with the
        given name is found in the data. If no method is found, it returns None.
        """
        for s in self.data:
            for m in s["methods"]:
                if name==m["name"]:
                    return m["method_id"]
    def get_interface_name_by_service_name(self,service_name:str)->str|None:
        """
        The function `get_interface_name_by_service_name` takes a service name as input and returns the
        corresponding interface name from a list of dictionaries, or None if no match is found.
        
        :param service_name: A string representing the name of the service
        :type service_name: str
        :return: a string value if a matching service name is found in the data, otherwise it returns None.
        """
        for s in self.data:
            if s["name"]==service_name:
                return s["interface"]
        return None