book = ["enviroment book"]

class Library( ):

    def displayBook(self)  :
        print(book)

    def lendbook(self):
        pass


    def addbook(self):
        print(" Which book you want to donate/give ? ")
        add = str(input())
        book.append(add)


    def returnbook(self):
        print(" Which book do yo want to return ? ")


if __name__ == '__main__':

    dillip = Library()

    while(True):
        print(f"Welcome to the Dilip library")
        print("For display of books press 1 \nFor lending book press 2 \nFor donating/give a book please press 3"
               "\nFor returning the book please press 4 \nTo exit the portal press 5   ")
        print("Please enter your choice ")
        choice=int(input())
        if choice == 1 :
            dillip.displayBook()
        elif choice == 2:
            dillip.lendbook()
        elif choice == 3:
            dillip.addbook()
        elif choice == 4:
            dillip.returnbook()
        elif choice == 5:
            break
        else:
            print("Entry invalid ")

    print(dillip)