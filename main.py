import os
from flask import Flask
from application import config
from application.config import LocalDevelopmentConfig
from application.database import db
from flask_restful import Api, Resource
import logging

logging.basicConfig(filename='debug.log', level=logging.DEBUG, format=f'%(asctime)s %(levelname)s %(name)s %(threadName)s : %(message)s')

app = None


def create_app():
    app = Flask(__name__, template_folder="templates")
    if os.getenv('ENV', "development") == "production":
        raise Exception("Currently no production config is setup")
    else:
        print("Starting local development")
        app.config.from_object(LocalDevelopmentConfig)
    api = Api(app)
    db.init_app(app)
    app.app_context().push()
    return app, api


app, api = create_app()

# Importing all controllers so they are loaded
from application.controllers import *

# Adding all restful controllers
from application.api import UserAPI

api.add_resource(UserAPI, "/api/user", "/api/user/<string:username>")

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5050)
