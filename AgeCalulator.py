# Python3 code to  calculate age in years
 

from datetime import date
 

def calculateAge(birthDate):

    today = date.today()

    age = today.year - birthDate.year -

         ((today.month, today.day) <

         (birthDate.month, birthDate.day))
 

    return age
