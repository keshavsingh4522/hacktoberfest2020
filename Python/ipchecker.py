# Created by BIGYAN RIJAL (Github: @theoptimist76)

# Importing the required libraries
import urllib.request
import re

# Checking the IP from website 
url = "http://checkip.dyndns.org"
print("\nWe will try to open this url, to get the IP Address: ", url)
request = urllib.request.urlopen(url).read()

# To check the raw request with the ip address 
print("\nThe raw request with the external IP Address is: \n\n", request)

# Finding the IP Address
theIP = str(request)
theIP = re.findall(r"\b\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}\b", theIP)

# Displaying the IP-Address
print("\nYour external IP Address is: ", theIP)
