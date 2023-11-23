# base_class.py
import json
import logging


class BaseClass:
    data: dict
    data_loaded: bool

    def load_data(self, file_path):
        logging.info("load data from file")
        try:
            with open(file_path, "r",encoding="UTF-8") as file:
                self.data = json.load(file)
                self.data_loaded = True
                logging.info("Class initialized successfully")
        except FileNotFoundError:
            logging.fatal(f"File in path: {file_path} does not exist")
            exit(1)
