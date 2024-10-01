# Created by BIGYAN RIJAL (Github: @theoptimist76)

# Enter the value to convert in proper convention
temp = input("Input the  temperature you would like to convert? (e.g. 45F, 102C etc.) : ")
degree = int(temp[:-1])
input = temp[-1]

#Checking if the value of temperature is in celcius or farhenheit 
if input.upper() == "C":
  result = int(round((9 * degree) / 5 + 32))
  output = "Fahrenheit"
elif input.upper() == "F":
  result = int(round((degree - 32) * 5 / 9))
  output = "Celsius"

# Checking proper convention of temperature values
else:
  print("Input proper convention of temperature.")
  quit()
  
# Display the output in celcius or farhenheit and vice versa
print("The temperature in", output, "is", result, "degrees.")
