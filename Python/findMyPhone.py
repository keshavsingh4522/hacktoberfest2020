#imports
# !pip install phonenumbers
import phonenumbers
from phonenumbers import geocoder
number = '+8801815136422'

pepNumber = phonenumbers.parse(number)
location = geocoder.description_for_number(pepNumber, "en")
print(location)

from phonenumbers import carrier
serviceInfo= phonenumbers.parse(number)
print(carrier.name_for_number(serviceInfo,"en"))

# !pip install opencage
import opencage
from opencage.geocoder import OpenCageGeocode

key='5e9cfcd5667d4593abdc3e096fa46960'
geocoder= OpenCageGeocode(key)
query=str(location)
result= geocoder.geocode(query)
print(result)

lat = result[0]['geometry']['lat']
lng = result[0]['geometry']['lng']
print(lat,lng)

# pip install folium
import folium

myMap = folium.Map(location=[lat,lng],zoom_start=9)
folium.Marker([lat,lng],popup=location).add_to(myMap)
myMap.save('mylocation.html')