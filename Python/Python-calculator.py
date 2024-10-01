import math
import random

output = 0
num1 = ""
operator = ""
num2 = ""
memStore = "Empty"

def abilitiesList():
    print("+...Addition")
    print("-...Subtraction")
    print("*...Multiplication")
    print("/...Division")
    print("^...Powers")
    print("/-...Square Roots ")
    print("!...Factorials (Input Cannot Be Negetave)")
    print("Abs...Absolute Value")
    print("d/r...Degrees To Radians")
    print("r/d...Radians To Degrees")
    print("pi...Returns PI")
    print("e...Returs 'e'")
    print("tau...Returns TAU (2xPI)")
    print("M+...Save input to memory")
    print("MR...Recall Memory")
    print("M-...Clear Memory")
    print("sin...Sine")
    print("cos...Cosine")
    print("tan...Tangent")
    print("asin...Arc Sine")
    print("acos...Arc Cosine")
    print("atan...Arc Tangent")
    print("log10...Log(10) of Input")
    print("log...Returns The Apropriate Log of the Input (input1 is the log power)")
    print("rand...Returns A Random Number Between 0 and 1")
    print("randint...Returns A Random Number Between The Two Inputs")
    print("//////////////////////////////////////////////////////////////////////////")

def askForNumInput(textPrompt):
    convertedNum = math.nan

    while True:
        num = input(textPrompt)
        try:
            float(num)
        except ValueError:
            print("ERROR: Syn: Invalid Num")
        else:
            convertedNum = float(num)
            break
    return convertedNum

while True:
    print("//////////////////////////////////////////////////////////////////////////")
    print("Type 'help' for a list of abilities")
    while True:
        operator = input("What operation do you want to perform? ")
        if operator == "help":
            abilitiesList()
        elif operator == "pi":
            print(math.pi)
        elif operator == "e":
            print(math.e)
        elif operator == "tau":
            print(math.pi*2)
        elif operator == "MR":
            print(str(memStore))
        elif operator == "M-":
            memStore = "Empty"
            print("Memory Cleared")
        elif operator == "rand":
            print(random.random())
        elif operator == "+" or operator == "-" or operator == "*" or operator == "/" or operator == "^" or operator == "/-" or operator == "!" or operator == "Abs" or operator == "d/r" or operator == "r/d" or operator == "M+" or operator == "M-" or operator == "MR" or operator == "sin" or operator == "cos" or operator == "tan" or operator == "asin" or operator == "acos" or operator == "atan" or operator == "log10" or operator == "log" or operator == "randint":
            break
        else:
            print("ERROR: Invalid Operator")

    while True:
        num1 = askForNumInput("First Number? ")
        if (operator == "asin" or operator == "acos") and (num1 > 1 or num1 < -1):
            print("ERROR: Math: 'asin' and 'acos' commands only accept inputs in range -1 to +1")
        elif operator == "!" and num1 < 0:
            print("ERROR: Math: Factorials only accept inputs > 0")
        else:
            break

    if not (operator=="/-" or operator=="!" or operator=="Abs" or operator=="d/r" or operator=="r/d" or operator=="M+" or operator=="sin" or operator=="cos" or operator=="tan" or operator=="asin" or operator=="acos" or operator=="atan" or operator=="log10"):
        while True:
            num2 = askForNumInput("Second Number? ")
            if  operator == "/" and num2 == "0":
                print("ERROR: Math: Canot divide by 0!")
            else:
                break

    if operator == "+":
        output = num1 + num2
        print("Your Answer: "+str(output))
    elif operator == "-":
        output = num1 - num2
        print("Your Answer: "+str(output))
    elif operator == "*":
        output = num1 * num2
        print("Your Answer: "+str(output))
    elif operator == "/":
        output = num1 / num2
        print("Your Answer: "+str(output))
    elif operator == "^":
        output = math.pow(num1,num2)
        print("Your Answer: "+str(output))
    elif operator == "/-":
        output = math.sqrt(num1)
        print("Your Answer: "+str(output))
    elif operator == "!":
        output = math.factorial(num1)
        print("Your Answer: "+str(output))
    elif operator == "Abs":
        output = math.fabs(num1)
        print("Your Answer: "+str(output))
    elif operator == "d/r":
        output = math.radians(num1)
        print("Your Answer: "+str(output))
    elif operator == "r/d":
        output = math.degrees(num1)
        print("Your Answer: "+str(output))
    elif operator == "M+":
        memStore = num1
        print("Number Stored")
    elif operator == "sin":
        output = math.sin(num1)
        print("Your Answer: "+str(output))
    elif operator == "cos":
        output = math.cos(num1)
        print("Your Answer: "+str(output))
    elif operator == "tan":
        output = math.tan(num1)
        print("Your Answer: "+str(output))
    elif operator == "asin":
        output = math.asin(num1)
        print("Your Answer: "+str(output))
    elif operator == "acos":
        output = math.acos(num1)
        print("Your Answer: "+str(output))
    elif operator == "atan":
        output = math.atan(num1)
        print("Your Answer: "+str(output))
    elif operator == "log10":
        output = math.log10(num1)
        print("Your Answer: "+str(output))
    elif operator == "log":
        output = math.log(num2, num1)
        print("Your Answer: "+str(output))
    elif operator == "randint":
        output = random.randint(num1, num2)
        print("Your Answer: "+str(output))