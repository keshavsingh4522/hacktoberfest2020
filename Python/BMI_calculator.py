height = float(input("Please Enter your height in cm: "))
weight = float(input("Please Enter your weight in kg: "))

BMI = weight / (height/100)**2

print(f"You BMI is {BMI}")

if BMI <= 18.4:
    print("You are underweight. Do Something!!!")
elif BMI <= 24.9:
    print("You are healthy.")
elif BMI <= 29.9:
    print("You are over weight. Do Something!!! ")
elif BMI <= 34.9:
    print("You are severely over weight. Do Something!!! ")
elif BMI <= 39.9:
    print("You are obese. Do Something!!!")
else:
    print("You are severely obese. God Bless You!!!")
