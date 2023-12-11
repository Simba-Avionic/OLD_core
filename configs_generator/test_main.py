# test_main.py
import unittest

from utils.end_file_generator import EndFileGenerator
from utils.base_class import BaseClass
from utils.interface import Interface
from utils.router import Router


class TestConfigsFileGenerator(unittest.TestCase):

    def testBaseClass(self):
        data=BaseClass()
        self.assertTrue(data.load_data('test_resource/services.json'))
        self.assertFalse(data.load_data('xyz'))


    def testInterfaceClass(self):
        interface=Interface('test_resource/interface.json')
        self.assertEqual(interface.get_by_interface_name("app1")["ip"],"192.168.1.1")
        self.assertEqual(interface.get_by_interface_name("app2")["ip"],"testowy.socket2")
        self.assertEqual(interface.get_by_interface_name("xyz"),None)
        self.assertEqual(interface.get_by_interface_name("app2")["port"],0)

    def testRouterClass(self):
        router=Router('test_resource/router.json')
        self.assertEqual(router.get_by_name("router 1")["interface"],"rut1")
        self.assertEqual(router.get_by_own_interface("rut1")["name"],"router 1")
        self.assertEqual(router.get_by_implemented_interfaces("app1")["interface"],"rut1")




    def test_all_funcion(self):
        expected_result = {'name': 'app1', 'service_id': 100, 'interface': {'ip': 'testowy.socket2', 'port': 0}, 'req_events': [{'name': 'app2/temp', 'event_id': 66652, 'service_id': 101}, {'name': 'app3/pressure', 'event_id': 2, 'service_id': 102}], 'db': {'app2/getcos': {'service_id': 101, 'method_id': 1, 'interface': {'ip': 'testowy.socket2', 'port': 0}}, 'app2/getcos2': {'service_id': 101, 'method_id': 2, 'interface': {'ip': 'testowy.socket2', 'port': 0}}, 'app3/getcos': {'service_id': 102, 'method_id': 1, 'interface': {'ip': '192.168.1.3', 'port': 1003}}}, 'conf': {'someconf': 'val', 'logLevel': 'kDebug'}}

        self.assertEqual(EndFileGenerator("app1", "resource/").generate_output_json(),expected_result)



if __name__=='__main__':
    unittest.main()