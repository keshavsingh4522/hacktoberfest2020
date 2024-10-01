import requests
import json

city = input("enter first region ")
city1 = input("enter second region ")
api_key = ''
url = "https://maps.googleapis.com/maps/api/distancematrix/json?units=imperial&"
r = requests.get(url + ("origins=") + city + ("&destinations=")+ city1 + ("&key=") + api_key)
time = r.json()
print(time)

base_url = "https://api.waqi.info"
token= '5688ab0da53ff69cef1bbc28a41882080eb6fd5e'

r = requests.get(base_url + f"/feed/{city}/?token={token}")
"City: {}, Air quality index: {}".format(r.json()['data']['city']['name'], r.json()['data']['aqi'])
f = requests.get(base_url + f"/feed/{city1}/?token={token}")
"City: {}, Air quality index: {}".format(r.json()['data']['city']['name'], r.json()['data']['aqi'])
xyz = f.json()
abc = r.json()
print ("Aqi for region 1 is",abc["data"]["aqi"])
print ("Aqi for region 2 is",xyz["data"]["aqi"])

#print(customerData)

a1 = abc["data"]["aqi"]
a2 = xyz["data"]["aqi"]


t1 = float(input("Enter 1st route time "))
t2 = float(input("Enter 2nd route time "))
da=abs(a1-a2)
dt=abs(t1-t2)
  
if 0<=da<=5 :
    af=0.1
elif 5<da<=20:
    af=0.2
elif 20<da<=50:
    af=0.3
elif 50<da<=100 :
    af=0.4
elif 100<da<150 :
    af=0.5
elif 150<da<=200 :
    af=0.6
else: 
    af=1 

if 0<=dt<=20:
    tf=0.1
elif 20<dt<=30:
    tf=0.3
elif 30<dt<=35:
    tf=0.3
elif 35<dt<=40:
    tf=0.5
elif 40<dt<=45:
    tf=0.7
elif 45<dt<=50:
    tf=1
else:
    tf=1.1
   

if af > tf :
         print("route will be decided on aqi prefrence")
         m = "aqi"
else: 
         print("route will be decided on time preference")
         m = "time"

if a1>a2 and t1>t2:
    print("route 2 is best")
elif a1<a2 and t1<t2:
    print("route 1 is best")
else:
    if m == "aqi" :
        if a1 > a2:
            print("Route 2 is best")
        else:
            print("Route 1 is best")
    elif m == "time" :
        if t1 > t2:
            print("Route 2 is best")
        else:
            print("Route 1 is best")
