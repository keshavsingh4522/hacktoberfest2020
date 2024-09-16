# your code goes here
import random
c = {1: '-------\n|     |\n|  •  |\n|     |\n-------',2: '-------\n|     |\n| • • |\n|     |\n-------',3: '-------\n|   • |\n|  •  |\n| •   |\n-------',4: '-------\n| • • |\n|     |\n| • • |\n-------',5: '-------\n| • • |\n|  •  |\n| • • |\n-------',6: '-------\n| • • |\n| • • |\n| • • |\n-------'};
com=random.randint(1,6)
print(" **  Computer Got  **")
print(c[com])
you=random.randint(1,6)
print("\n\n\n **  You Got  **")
print(c[you])
print()
print()
if you==com:
  print("It's a draw!!")
elif you>com:
  print("Hurray!!! You won..")
else:
  print("Uff :(.. You lost!!")