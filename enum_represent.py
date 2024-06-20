from enum import Enum

class Day(Enum):
    MONDAY = 1
    TUESDAY = 2
    WEDNESDAY = 3

# print the enum member
print(Day.MONDAY)

# get the name of the enum member
print(Day.MONDAY.name)

# get the value of the enum member
print(Day.MONDAY.value)
