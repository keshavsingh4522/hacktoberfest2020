# import all the things
from Dog import Dog
from tkinter import *
from tkinter.scrolledtext import ScrolledText
from tkinter.filedialog import askopenfilename
from tkinter.filedialog import asksaveasfilename

# Create a class named PetCreator
class PetCreator:

    #Define the class's init function
    def __init__(self):
    
        # Create a window named window
        window = Tk()
        
        # Set the window's title to be "Pet Creator"
        window.title("Pet Creator")
        
        #Set window size to 275 by 525 pixels using the .geometry() method
        window.geometry('275x525')
        
        # Don't allow resizing the window by using the .resizable(0, 0) method
        window.resizable(0, 0)

        #Create a menu bar named menubar
        menubar = Menu()
        
        # Add the menubar to the window
        window.config(menu = menubar)
        
        # create a new menu named operationMenu
        operationMenu = Menu(menubar, tearoff = 0)
        
        # add a cascading menu to menubar named "Operations"
        menubar.add_cascade(label = 'Operations', menu = operationMenu)
        
        # add a command to the operationMenu to "Open File", with a command that calls the open function
        operationMenu.add_command(label = 'Open File', command = self.open)
        
        # add a command to the OperationMenu to "Save File", with a command that calls the save function
        operationMenu.add_command( label = 'Save File', command = self.save)
        
        #add a command to the OperationMenu to "Exit", with a command that closes the program (window.destroy)
        operationMenu.add_command(label = 'Exit', command = window.destroy)


        # create a font for our headline with 'arial' font, size 20 pixels, and style of 'bold'
        labelFont = "Arial 20 bold"
        
        # create a frame named frame1 for our window
        frame1 = Frame(window)
        
        # pack frame1 into the window
        frame1.pack()
        
        # create a label named labelTitle and set the text to be "Pet Creator"
        labelTitle = Label(frame1, text = "Pet Creator")
        
        # use the .config method to use labelfont as labelTitle's font definition
        labelTitle.config(font = labelFont)
        
        # pack labelTitle onto the frame
        labelTitle.pack()

        # create frame2 for our window
        frame2 = Frame(window)
        
        # pack frame2 into the window
        frame2.pack() 

        # declare a StringVar() for each of our entry widgets, self.breed, self.name, self.weight, and self.age
        self.breed = StringVar()
        
        self.name = StringVar()
        
        self.weight = StringVar()
        
        self.age = StringVar()

        # Create a label named labelBreed with text "Enter breed:" for frame2
        labelBreed = Label(frame2, text = "Enter breed:")
        
        # Create a label named labelName with text "Enter name:" for frame2
        labelName = Label(frame2,text = "Enter name:")

        # Create a label named labelWeight with text "Enter weight:" for frame2
        labelWeight = Label(frame2,text = "Enter weight:")

        # Create a label named labelAge with text "Enter age:" for frame2
        labelAge = Label(frame2,text = "Enter age:")

        # Create a label named labelSpacer with text " " for frame2
        labelSpacer = Label(frame2,text = " ")

        # Create a label named labelSpacer2 with text " " for frame2
        labelSpacer2 = Label(frame2,text = " ")


        # Create an entry widget named entryBreed, associate it with frame2, and set the text variable to self.breed
        entryBreed = Entry(frame2, textvariable = self.breed)
        
        # Create an entry widget named entryName, associate it with frame2, and set the text variable to self.name
        entryName = Entry(frame2, textvariable = self.name)

        # Create an entry widget named entryWeight, associate it with frame2, and set the text variable to self.weight
        entryWeight = Entry(frame2, textvariable = self.weight)

        # Create an entry widget named entryAge, associate it with frame2, and set the text variable to self.age
        entryAge = Entry(frame2, textvariable = self.age)


        # place labelSpacer in row 1 of the grid
        labelSpacer.grid(row = 0)

        # place labelBreed in row 2, column 1 of the grid
        labelBreed.grid(row = 1 , column = 1)
        
        # place entryBreed in row 2, column 2 of the grid
        entryBreed.grid(row = 1 , column = 2)

        # place labelName in row 3, column 1 of the grid
        labelName.grid(row = 2 , column = 1)

        # place entryName in row 3, column 2 of the grid
        entryName.grid(row = 2, column =2)

        # place labelWeight in row 4, column 1 of the grid
        labelWeight.grid(row = 3 , column = 1)

        # place entryWeight in row 4, column 2 of the grid
        entryWeight.grid(row = 3 , column = 2)

        # place labelAge in row 5, column 1 of the grid
        labelAge.grid(row = 4 , column = 1)

        # place entryAge in row 5, column 2 of the grid
        entryAge.grid(row = 4 , column = 2)

        # place labelSpacer2 in row 6 of the grid
        labelSpacer2.grid(row = 5)
        

        # create a new fram called frame3 for our window
        frame3 = Frame(window)

        # pack frame3 into the UI
        frame3.pack()
        # create a new label named labelNotes in frame 3, with text "Enter pet instructions from owner."
        labeNotes = Label(frame3, text = "Enter pet instructions from owner" )
        
        # pack labelNotes onto the UI
        labeNotes.pack()

        # create a Scrollbar widget named scrollbar into frame3
        scrollbar = Scrollbar(frame3)
 
        # pack the scrollbar on the right side of the UI, with Y selected as the fill option
        scrollbar.pack(side = RIGHT, fill = Y)
       
        # create a new text widget named text with the dimensions below
        self.text = Text(frame3, width = 40, height = 20, wrap = WORD, yscrollcommand = scrollbar.set)
        
        # pack text onto the UI
        self.text.pack()

        # configure the scrollbar to control the text widget
        scrollbar.config(command = self.text.yview)

        # set our window in a mainloop
        mainloop()


    # Create a function named save that accepts no arguments (self)
    def save(self):    
        
        # Declare a string named breed, store the contents of the self.breed StringVar
        # in the new string. Hint: use the .get() method. Make sure to trim whitespace in the entry widget!
        breed = self.breed.get().strip()

        # Do the same thing for a new string named name, storing self.name StringVar
        name = self.name.get().strip()

        # Do the same thing for a new string named weight, storing self.weight StringVar
        weight = self.weight.get().strip()
      
        # Do the same thing for a new string named age, storing self.age StringVar
        age = self.age.get().strip()
    

        # Create a new dog object and pass the 4 required parameters to it using the 4 variables you just created.
        # This will store the text in the widgets in the object data fields.
        storeDog = Dog(breed, name, weight, age)
                

        # Declare a new variable named notes, getting and storing the whitespace-trimmed contents of the text widget into it.
        notes = self.text.get('1.0', END).strip()
        
        # declare a new MULTILINE string named savetext, using your 4 Dog class get methods.
        # you will need to concatenate each field of the string with the + operator, and ensure
        # that each field is separated by a line feed.
        # Also, make sure that you add the notes variable at the end of your string definition
        savetext = (storeDog.getBreed() + '\n' + storeDog.getName() + '\n' + storeDog.getWeight() + '\n' + storeDog.getAge() + '\n' + notes)      

        # create a new file object that saves to .txt by default
        filenameforWriting = asksaveasfilename(defaultextension=".txt", filetypes=(("Text file", "*.txt"),("All Files", "*.*") ))
        
        # create a new object named outfile that opens our new filenameforWriting for write operations.
        outfile = open(filenameforWriting, "w")
        
        # write the contents of savetext to the file
        outfile.write(savetext)
        
        # close the file
        outfile.close()

    # Create a function named open that accepts no arguments (self)
    def open(self):         
    
        # create a file object named filenameforReading that looks for .txt files
        filenameforReading = askopenfilename(filetypes=[("Text files", "*.txt")])
       
        # create a new object named infile that opens our desired file for reading.
        infile = open(filenameforReading, "r")
        
        # declare a list named lineList
        lineList = []
        

        # create a for loop that iterates each line in the infile object  
        for line in infile:
        
            # append the current line to the lineList list
            lineList.append(line)
            

        # close the infile file
        infile.close()    
        
        # set the self.breed StringVar to the 0th element in the lineList list. Don't forget to trim whitespace!
        self.breed.set(lineList[0].strip())
        
        # set the self.name StringVar to the 1st element in the lineList list. Don't forget to trim whitespace!
        self.name.set(lineList[1].strip())
        
        # set the self.weight StringVar to the 2nd element in the lineList list. Don't forget to trim whitespace!
        self.weight.set(lineList[2].strip())
        
        # set the self.age StringVar to the 3rd element in the lineList list. Don't forget to trim whitespace!
        self.age.set(lineList[3].strip())
        
        # delete all the text from the text widget
        self.text.delete('1.0', END)
        
        # use the .insert method to put the value of the 4th element in the lineList list in the text widget.
        # This accounts for new lines in the notes field by creating a string and joining the list of lines
        # from the 4th element in lineList to the end of lineList.
        notestring = str() 
        
        self.text.insert(END, notestring.join(lineList[4:]))

# Call PetCreator() 
PetCreator()
