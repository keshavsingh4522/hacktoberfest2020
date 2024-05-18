from geopy.geocoders import Nominatim

text = int(input('Enter your Zip Code or Postal Code... '))

geolocator = Nominatim(user_agent="geoapiExercises")
location = geolocator.geocode(text)

print(location)
