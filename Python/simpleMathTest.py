import random as r,time as t,math as m

operations=['+','-','*','/']

while True:

    num1=r.randint(0,50)

    num2=r.randint(1,10)

    operation=r.choice(operations)

    if operation=='+':

        print(num1,' + ',num2)

        ans=int(input("\nEnter sum : "))

        if ans==(num1+num2):

            print("\n YOU ARE RIGHT.\n")

        else:

            print("\n TRY AGAIN\n")

    if operation=='-':

        print(num1,' - ',num2)

        ans=int(input("\nEnter difference : "))

        if ans==num1-num2 or num2-num1:

            print("\n YOU ARE RIGHT.\n")

        else:

            print("\n TRY AGAIN\n")

    if operation=='*':

        print(num1,' × ',num2)

        ans=int(input("\nEnter product : "))

        if ans==(num1*num2):

            print("\n YOU ARE RIGHT.\n")

        else:

            print("\n TRY AGAIN\n")

    if operation=='/':

        print(num1,' ÷ ',num2)

        ans=int(input("\nEnter quotient : "))

        if ans==(num1//num2):

            print("\n YOU ARE RIGHT.\n")

        else:

            print("\n TRY AGAIN\n")

  

