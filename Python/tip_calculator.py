print("Welcome to tip calculator")
bill = float(input("What was the total bill? $"))
tip_percentage = int(input("What percentage tip would you like to give? 10, 12, or 15? "))
no_of_people = int(input("How many people to split the bill?"))

bill_with_tip = bill + ((bill * tip_percentage) / 100)
bill_each_people = round((bill_with_tip / no_of_people), 2)
print(f"Each people should pay: ${bill_each_people}")

