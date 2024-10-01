print("Program to find area and perimeter of a circle")
print("choose your desired option no")
print("1.Find perimeter")
print("2.Find area")
inp=int(input("enter the option number e.g. 1 or 2:"))
a=int(input("enter the radius of the circle:"))
if (inp==1):
   perimeter=2*3.14*a
   print("perimeter of the circle is:", perimeter)
elif (inp==2):
   area=3.14*a**2
   print("Area of this circle is:", area)
else:
   print("invalid input,please enter a number between 1 or 2")
