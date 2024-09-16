import requests
import json
username=input('Enter Username')

url=f'https://api.github.com/users/{username}'

user_data=requests.get(url).json()

with open('python\Github Stalker\data.txt', 'w') as outfile:
    json.dump(user_data, outfile,indent=4)

print(user_data)