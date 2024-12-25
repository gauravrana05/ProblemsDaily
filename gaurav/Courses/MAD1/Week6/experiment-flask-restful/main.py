import os 
from flask import Flask
from flask_restful import Resource, Api
from application import config 
from application.config import LocalDevelopmentConfig
from application.database import db


app = None
api = None  

def create_app():
  app = Flask(__name__, template_folder="templates")
  if os.getenv('ENV',"development") == "production":
    raise Exception ("currently no production environment is setup")
  else:
    print("Starting Local Development")
    app.config.from_object(LocalDevelopmentConfig)
  db.init_app(app)
  api = Api(app)
  
  app.app_context().push()
  return app, api

app, api = create_app()

from application.controllers import *
from application.api import UserAPI

api.add_resource(UserAPI, "/api/user/" , "/api/user/<string:username>")


if __name__ == "__main__":
  app.run(host='0.0.0.0', port = 8000)
  
  

