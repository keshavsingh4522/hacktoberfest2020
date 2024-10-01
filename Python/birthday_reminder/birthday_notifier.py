import json
import time

class birthdayLogger:

    # variables for usage
    def __init__(self):
        self.b_list = []
        self.results = {}
        self.records = 0
        self.matches = 0
        self.json_file = 'database.json'
        try:
            with open(self.json_file, 'r') as json_file: 
                self.data = json.load(json_file)
        except Exception as e:
            print(e)
            print(self.firstEntry())

    # creates a new file and adds first entry in the file
    def firstEntry(self):
        name, date_of_birth = self.validateInput()
        new_entry = {
            'birthday': [
                {
                    'name': name,
                    'date_of_birth': date_of_birth
                }
            ]
        }
        with open('sample.json', 'w') as f:  
            json.dump(new_entry, f, indent=4)
            return ("New file has been created and the first entry has been successfully added!")
    
    # function to write to JSON 
    def writeJson(self, filename='database.json'): 
        with open(filename,'w') as f: 
            json.dump(self.data, f, indent=4)

    # function to validate inputs
    def validateInput(self):
        # saves current year for validation purposes
        from datetime import datetime
        currentYear = datetime.now().year

        # inputs for json file
        # validation for name
        while 1:
            name = input('Enter a name: ')
            try:
                name = int(name)
            except Exception as e:
                pass
            if type(name) == int:
                print('Please Enter a valid name.')
            else:
                break
        # validation of date of birth
        while 1:
            date_of_birth = input('Enter Date of Birth(DD/MM/YYYY): ')
            dob_list = date_of_birth.split('/')
            if len(dob_list) < 3:
                print('Please Enter in DD/MM/YYYY format')
            else:
                for x in range(len(dob_list)):
                    date, month, year = dob_list
                    date = int(date)
                    month = int(month)
                    year = int(year)
                if not (0 < date < 32):
                    print('Please Enter a valid date')
                elif not (0 < month < 13):
                    print("Please Enter a valid month")
                elif not (1900 < year <= currentYear):
                    print("Please Enter a valid year")
                else:
                    if 0 < date < 10 or 0 < month < 10:
                        date, month, year = date_of_birth.split(' ')
                        date = date.zfill(2)
                        month = month.zfill(2)
                        date_of_birth = date+' '+month+' '+year
                    date_of_birth = date_of_birth.replace(' ', '-')
                    self.b_list = [name, date_of_birth]
                    # print(self.b_list)
                    return self.b_list

    # function to add new entry
    def addNewEntry(self):
        name, date_of_birth = self.validateInput()
        temp = self.data['birthday']       # loading json birthdate section
        # formatting new entry
        newEntry = {
            'name': name,
            'date_of_birth': date_of_birth,
        }
        temp.append(newEntry)   # appending data to json
        # self.data
        self.writeJson()
        return 'New Entry Added'

    # searching dob using name
    def find(self, name):
        self.records = 0
        self.matches = 0
        birthday = self.data['birthday']
        for i in birthday:
            names = i['name']
            self.records += 1
            if name in names:
                dob = i['date_of_birth']
                print(f'{names} birthday is on {dob}')
                self.matches += 1
        return (f'There are {self.matches} found from {self.records}')

    # returning all entries
    def allEntries(self):
        birthday = self.data['birthday']
        for i in birthday:
            name = i['name']
            dob = i['date_of_birth']
            # print(f'{name} is on {dob}')
            self.results[name] = dob
            self.records += 1
        print(f'There are {self.records} records')
        return self.results


def birthdayChecker():
    from plyer import notification 
    from threading import Timer

    Timer(43200.0, birthdayChecker).start()  # the function refreshes every 12 hours if constantly runs
    today = time.strftime('%d%m')
    bd = birthdayLogger()
    all_entries = bd.allEntries()
    for names in all_entries:
        dates = str(all_entries[names])
        dates = dates.split('-')
        dates.pop()
        dates = ''.join(dates)
        if dates == today:
            notification.notify( 
                title="BirthDay ", 
                message=f'Wish {names} for birthday', 
                timeout=10,
            )


# checking the birthdays every 12 hours
birthdayChecker()

# loop for adding, searching entries
# if you want to run it in background comment out below code and uncomment when adding, searching entries
while 1:
    bd = birthdayLogger()
    print('Please enter the option number with which you wish to proceed:\n 1)Add a new entry\n 2)Display all entries\n 3)Search for a name\n 4)Quit')
    i = int(input("Enter your choice: "))
    if i==1:
        print(bd.addNewEntry())
    elif i==2:
        print(bd.allEntries())
    elif i==3:
        i = input("Enter name for searching:")
        print(bd.find(i))
    elif i==4:
        break



