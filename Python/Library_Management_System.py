'''
In this LMS,
            there are  4 basic function that is 
            1. Display_Book
            2. Lend_Book
            3. Add_Book
            4. Remove_Book

'''
import sys
class LMS:
    def __init__(self,book_list,book_name):
        self.book_list = book_list
        self.book_name = book_name
        self.book_dict = {}

    def display_availableBook(self):
        print(f"We have a following books in our library :{self.book_name}")
        print("The books that are available to us are:\t")
        for book in self.book_list:
            print(book)
    def lend_book(self,Lender_name,book):
        if book not in self.book_dict.keys():
            self.book_dict.update({book:Lender_name})
            if book in self.book_list:
                print("Lender of book information has been updated.\t\n You can lend the book now")
            else:
                print("Sorry!\n\tThis book is't available in our library at this moment.")
        else:
            print(f"The book has already taken by {self.book_dict[book]}")
    def add_book(self,book):
        self.book_list.append(book)
        print(f"{book} book has been added in book_list")
        
    def return_book(self,book):
        self.book_dict.pop(book)
        print(f"{book} has been removed from book_dictionary")

Safeer = LMS(["English","Applied Physics","ICT","MS","AR","IA","Programming fundamental","DS","OOP"], 'APPSOUL Library Bahawalpur')
while True:
    print(f"Hello SIr!\n\tWelcome to the {Safeer.book_name}. Please Enter your choice that you wanna do... ")
    print("""
            =======LIBRARY MENU ==========
    1. Display Book
    2. Lend Book
    3. Add Book
    4. Return Book
    5. exit
    
    """)
    Choice = int(input("Enter the corresponding function  number :\t"))
    if Choice ==1:
        Safeer.display_availableBook()
    elif Choice ==2:
        Lender_name = input("Enter the name of lender of book :\t")
        book = input("Enter the book name that a lender is lending :\t")
        Safeer.lend_book(Lender_name, book)
    elif Choice ==3:
        book = input("enter the name of a book :\t")
        Safeer.add_book(book)
    elif Choice ==4:
        book = input("Enter the name of book:\t")
        Safeer.return_book(book)
    elif Choice == 5:
        sys.exit()
    else:
        print("Warning\t\nYou enter the invalid input!")
    abc = input("Enter 'Y' for continue the function & 'N' for exit the function :\t ")
    abc = abc.upper()
    if abc == 'Y':
        continue
    elif abc == 'N':
        print("Thanks Sir for visiting out LMS\n Have a Nice Day.")
        exit()
    else:
        print("You enter the invalid input: \t")
main()
