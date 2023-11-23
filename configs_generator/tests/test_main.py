# test_main.py
from utils.end_file_generator import EndFileGenerator

def test_generate_output_json():
    """
    The function `test_generate_output_json()` tests the `generate_output_json()` method of the
    `EndFileGenerator` class.
    """
    generator = EndFileGenerator("app1", "resource/")
    result = generator.generate_output_json()

    expected_result = {
    "name": "app1",
    "service_id": 100,
    "interface": {
        "ip": "",
        "ipc": "testowy.socket2",
        "port": 0
    },
    "methods": [
        {
            "method_id": 1,
            "name": "getcos"
        }
    ],
    "db": {
        "app2/getcos": {
            "service_id": 101,
            "method_id": 1,
            "interface": {
                "name": "app2",
                "ip": "",
                "ipc": "testowy.socket2",
                "port": 0
            }
        },
        "app2/getcos2": {
            "service_id": 101,
            "method_id": 2,
            "interface": {
                "name": "app2",
                "ip": "",
                "ipc": "testowy.socket2",
                "port": 0
            }
        },
        "app3/getcos": {
            "service_id": 102,
            "method_id": 1,
            "interface": {
                "name": "app3",
                "ip": "192.168.1.3",
                "ipc": "",
                "port": 1003
            }
        }
    },
    "conf": {
        "someconf": "val",
        "logLevel": "kDebug"
    }
}

    assert result == expected_result
