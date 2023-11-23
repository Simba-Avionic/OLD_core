import logging
from utils.validator import SimBaConfigsValidator
from utils.base_class import BaseClass



# The `Router` class is a subclass of `BaseClass` that provides methods for retrieving router data
# based on name, interface, and implemented interfaces, as well as checking if two interfaces are
# present in the same router.
class Router(BaseClass):
    def __init__(self,filepath:str):
        self.load_data(filepath)
        self.data=self.data["routers"]
        if not SimBaConfigsValidator().validate_routers(filepath):
            logging.warning("Invalid Router Schema")

    def get_by_name(self,name:str)->dict|None:
        """
        The function `get_by_name` takes a name as input and returns a dictionary containing the data
        associated with that name, or None if no matching name is found.
        
        :param name: A string representing the name of the item you want to retrieve from the data
        :type name: str
        :return: a dictionary if a match is found for the given name in the data list. If no match is found,
        it returns None.
        """
        for r in self.data:
            if r["name"]==name:
                return r
        return None
    def get_by_own_interface(self,interface_name:str)->dict|None:
        """
        The function `get_by_own_interface` takes an interface name as input and returns the corresponding
        dictionary from the data list if found, otherwise it returns None.
        
        :param interface_name: A string representing the name of the interface to search for in the data
        :type interface_name: str
        :return: a dictionary if a match is found for the given interface name in the data list. If no match
        is found, it returns None.
        """
        for r in self.data:
            if interface_name==r["interface"]:
                return r
        return None
    def get_by_implemented_interfaces(self,interface_name:str)->dict|None:
        """
        The function `get_by_implemented_interfaces` searches for a dictionary in a list of dictionaries
        based on a given interface name and returns the first matching dictionary, or None if no match is
        found.
        
        :param interface_name: The parameter `interface_name` is a string that represents the name of the
        interface you want to search for in the data
        :type interface_name: str
        :return: The method `get_by_implemented_interfaces` returns a dictionary if a matching interface
        name is found in the `interfaces` list of any element in the `data` list. If no match is found, it
        returns `None`.
        """
        for r in self.data:
            if interface_name in r["interfaces"]:
                return r
        return None
    def service_is_in_the_same_router(self,interface_name1:str,interface_name2:str):
        """
        The function checks if two interface names are present in the same router's interfaces.
        
        :param interface_name1: The first interface name to check if it is in the same router as the second
        interface
        :type interface_name1: str
        :param interface_name2: The `interface_name2` parameter is a string that represents the name of the
        second interface
        :type interface_name2: str
        :return: a boolean value. It returns True if both interface_name1 and interface_name2 are found in
        the "interfaces" list of any dictionary in the self.data list. Otherwise, it returns False.
        """
        for r in self.data:
            if interface_name1 in r["interfaces"] and interface_name2 in r["interfaces"]:
                return True
        return False