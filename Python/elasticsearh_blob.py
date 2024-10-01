import requests
import json
import datetime
import logging
from threading import Thread
from queue import Queue
import glob
import os
import functools
headers = {"Content-Type":"application/json"}
path = r'file path .tgz file'


elastic_url = "http://%s/%s/%s" % (
    1.1.1.1:8080",
    "index name",
    "file path"
)
import base64

try:
    with open(path, "rb") as f:
        bytes = f.read()
        encoded = str(base64.b64encode(bytes).decode("utf-8") )

    upload_data = {}
    upload_data["name"] = "file path"
    upload_data["blob"] = encoded
except Exception as e:
    print(str(e))

try:
    # print(upload_data)
    resp_elastic = requests.put(
        elastic_url,
        headers=headers,
        data=json.dumps(upload_data),
        verify=False
    )
    print("ES Entry completed for {}".format(path))
except Exception as e:
    print(e)
