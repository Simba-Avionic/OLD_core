router_schema = {
    'routers': {
        'type': 'list',
        'schema': {
            'type': 'dict',
            'schema': {
                'name': {'type': 'string', 'required': True},
                'interfaces': {'type': 'list', 'schema': {'type': 'string'}},
                'interface': {'type': 'string', 'required': True}
            }
        }
    }
}


interface_schema = {
    'interfaces': {
        'type': 'list',
        'schema': {
            'type': 'dict',
            'schema': {
                'name': {'type': 'string', 'required': True},
                'ip': {'type': 'string', 'required': True, 'regex': r'\b(?:\d{1,3}\.){3}\d{1,3}\b'},  # Sprawdź format IP
                'ipc': {'type': 'string', 'required': True},
                'port': {'type': 'integer', 'required': True, 'min': 0, 'max': 99999} 
            }
        }
    }
}

services_schema = {
    'services': {
        'type': 'list',
        'schema': {
            'type': 'dict',
            'schema': {
                'name': {'type': 'string'},
                'service_id': {'type': 'integer'},
                'interface': {'type': 'string'},
                'methods': {
                    'type': 'list',
                    'schema': {
                        'type': 'dict',
                        'schema': {
                            'method_id': {'type': 'integer'},
                            'name': {'type': 'string'},
                        }
                    }
                },
                'req_services': {'type': 'list', 'schema': {'type': 'string'}},
                'conf': {
                    'type': 'dict',
                    'schema': {
                        'someconf': {'type': 'string'},
                        'logLevel': {'type': 'string', 'allowed': ['kDebug', 'kInfo', 'kError']}
                    }
                }
            }
        }
    }
}