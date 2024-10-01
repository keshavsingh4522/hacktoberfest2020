# This program displays current weather of the location searched

import requests
import json

# NOTE: This program will not work without your OpenWeatherMap API key
# Do not share this key with anyone
API_KEY = 'YOUR_API_KEY'

city = str(input("Enter city name to search for its weather: "))

try:
    r = requests.get(f"http://api.openweathermap.org/data/2.5/weather?q={city}&appid={API_KEY}")
    jsonData = json.loads(r.text)
    # print(jsonData)

    if jsonData["cod"] == 200:
        latitude = jsonData["coord"]["lat"]
        longitude = jsonData["coord"]["lon"]
        mainWeather = jsonData["weather"][0]["main"]
        description = jsonData["weather"][0]["description"]
        temp = int(jsonData["main"]["temp"]) - 273
        feelsLike = int(jsonData["main"]["feels_like"]) - 273
        tempMin = int(jsonData["main"]["temp_min"]) - 273
        tempMax = int(jsonData["main"]["temp_max"]) - 273
        pressure = jsonData["main"]["pressure"] # in hPa (hectopascal)
        humidity = jsonData["main"]["humidity"] # in %
        visibility = jsonData["visibility"] # in meter
        windSpeed = jsonData["wind"]["speed"] # in meter per second
        windDir = jsonData["wind"]["deg"] # in degree
        clouds = jsonData["clouds"]["all"] # in %
        print(f"City Searched: {city}")
        print(f"Latitude: {latitude}")
        print(f"Longitude: {longitude}")
        print(f"Weather: {mainWeather}")
        print(f"Description: {description}")
        print(f"Average Temperature: {temp} degree C")
        print(f"Feels Like: {feelsLike} degree C")
        print(f"Min Temperature: {tempMin} degree C")
        print(f"Max Temperature: {tempMax} degree C")
        print(f"Pressure: {pressure} hectopascal")
        print(f"Humidity: {humidity} %")
        print(f"Visibility: {visibility} meter")
        print(f"Wind Speed: {windSpeed} meter per second")
        print(f"Wind Direction: {windDir} degree")
        print(f"Clouds: {clouds} %")

    elif jsonData["cod"] == "404":
        print("City not found. Please refine your search.")

except:
    print("There was some error in the process. Please try again.")