import datetime
import time

import requests



def weather():
    """A simple function that fetches weather information for the provided location"""
    city = ""
    city = str(input("Enter the name of the city: "))
    start = datetime.datetime.now()
    openweathermapkey = "" # Enter your API Key here. You can get it from here - https://openweathermap.org/api
    if city == "":
        print("\nYou need to specify a location!")
        time.sleep(10)
        exit()
    else:
        city = city.lower()
        city = city.replace(' ',',')
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) '
                             'Chrome/41.0.2228.0 Safari/537.36'}
        api = f"http://api.openweathermap.org/data/2.5/weather?q={city}&units=metric&appid={openweathermapkey}"
        r = requests.get(api, headers=headers)
        response = r.json()
        if response['cod'] == 200:

            cityname = response['name']
            country = response['sys']['country']
            location = f"{cityname}, {country}"

            cityid = response['id']
            longitude = response['coord']['lon']
            latitude = response['coord']['lat']

            main = response['weather'][0]['main']
            descriptiion = response['weather'][0]['description']
            status = f"{main}({descriptiion})"

            feels_likec = int(response['main']['feels_like'])
            feels_likef = int((feels_likec * 1.8) + 32)

            tempc = int(response['main']['temp'])
            tempf = int((tempc * 1.8) + 32)

            tempminc = int(response['main']['temp_min'])
            tempminf = int((tempminc * 1.8) + 32)

            tempmaxc = int(response['main']['temp_max'])
            tempmaxf = int((tempmaxc * 1.8) + 32)

            humidity = response['main']['humidity']

            pressuret = response['main']['pressure']
            pressurep = round(pressuret / 51.72, 2)

            sunrise_raw = response['sys']['sunrise']
            sunrise = time.strftime("%H:%M", time.gmtime(int(sunrise_raw)))

            sunset_raw = response['sys']['sunset']
            sunset = time.strftime("%H:%M", time.gmtime(int(sunset_raw)))

            windk = int(response['wind']['speed'])
            windm = int(windk * 0.62)


            print(f"\n\n| Powered by openweathermap.org | ID: {cityid}\n\nLocation: {location}\nFeels like: {feels_likec}°C ({feels_likef}°F)\nTemperature: {tempc}°C ({tempf}°F)\nMin: {tempminc}°C ({tempminf}°F)\nMax: {tempmaxc}°C ({tempmaxf}°F)\nCoordinates: {longitude} , {latitude}\nStatus: {status}\nAir Pressure: {pressurep} psi\nHumidity: {humidity} vapour/m3\nWind Speed: {windk} km/h | {windm} m/s\nSunrise: {sunrise} GMT\nSunset: {sunset} GMT")
            end = datetime.datetime.now()
            total_time = (end - start).total_seconds()
            print(f"\nDone!")

            input(f"Total time taken : {total_time} seconds")
        else:
            print("\nNo data found")
            time.sleep(3)
            exit()

if __name__ == '__main__':
    weather()
