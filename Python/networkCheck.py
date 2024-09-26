#Python program to check connection

import requests
import socket

def check_localhost():
	localhost = socket.gethostbyname('localhost')
	if localhost == '127.0.0.1':
		print("True")

def check_connectivity():
	request = requests.get("https://www.google.com")
	if request.status_code == 200:
		print('True')

check_localhost()
check_connectivity()
