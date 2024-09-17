import json
import pprint
import sys
from urllib.request import urlopen

import argparse
parser = argparse.ArgumentParser(description='Pretty print a local json file or json file from the internet')
parser.add_argument("Type", help="Either URL or file, choose whether you want to open a remote or local file")
parser.add_argument("Path", help="Path of file or URL")
args = parser.parse_args()

def printFILE(FILE):
    with open(FILE, "r") as f:
        data=f.read()
        dic=json.loads(data)
        pprint.pprint(dic, sort_dicts=False)
def printURL(URL):
    with urlopen(URL) as url:
        http_info = url.info()
        raw_data = url.read().decode('utf-8')
    project_info = json.loads(raw_data)
    result = {'headers': http_info.items(), 'body': project_info}
    pprint.pprint(result, sort_dicts=False)

if args.Type.lower() == "file":
    printFILE(args.Path)
elif args.Type.lower() == "url":
    printURL(args.Path)
