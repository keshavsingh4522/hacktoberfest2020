import tkinter as tk
from PIL import Image, ImageTk

# create instance
window = tk.Tk()
# set default window size
window.geometry("500x500")
# set min window size
window.minsize(300, 200)
# set max window size
window.maxsize(700, 600)
# add a title
window.title("ImageGallery")

# widget classes -> Label, Entry, Text, Button, Frame

# Add header
tk.Label(window, 
    compound=tk.TOP, 
    text='--------- Image Gallery ---------',
    pady=20, # padding Vertical
    font=("Courier", 18, "bold") # change the font OR "Courier  18 bold"
).pack()

# Add a frame
form_frame = tk.Frame()
form_frame.pack()

# add a label to the frame
label = tk.Label(
    master=form_frame,
    text="Go to (1-8)",
    foreground="white", # set text-color to white
    background="orange", # set background-color to orange
    padx=10, # padding horizontal
    pady=2 # padding vertical
    )
label.grid(row=1, column=1)

# add an input box to the frame
userInput = tk.Entry(
    master=form_frame,
    fg="purple",
    bg="white",
    width=20 # width of input
    )
userInput.grid(row=1, column=2)

# add a button
button = tk.Button(
    master=form_frame,
    text="Go",
    fg="red", # set text-color to white
    command=lambda : goTO(userInput.get()),
    padx=6, # padding horizontal
    )
button.grid(row=1, column=3)

# Add another frame
image_frame = tk.Frame()
image_frame.pack()

image_list = ['anime.png', 'panda_face.png', 'dog.png', 'shoepping.png', 
            'color_palette.png', 'android.png','logo.png', 'shoe.png']
current = 0

# Add an image-label
image_label = tk.Label(window, compound=tk.BOTTOM, width=300, height=300)
image_label.pack()

button_frame = tk.Frame(window)
button_frame.pack()

tk.Button(button_frame, text='Previous', command=lambda: move(-1)).grid(row=1, column=1)
tk.Button(button_frame, text='Next', command=lambda: move(+1)).grid(row=1, column=3)
tk.Button(text='Quit', command=window.quit, fg='red', font=("Courier", 15)).pack(side=tk.BOTTOM)

# open image
# image = Image.open('1.png')
# photo = ImageTk.PhotoImage(image)

# # Add image-label inside frame
# image_label = tk.Label(
#     master=image_frame, # attach label to the frame
#     text="This is label inside frame",
#     image=photo,
#     )
# image_label.grid(row=1, column=1)


def goTO(text):
    global current
    current = 0
    pos = 0
    try:
        pos = int(text)
    except :
        pass
    move(pos-1)
    # set input-box to null
    userInput.delete(0, len(text))

def move(pos):
    global current, image_list
    if not (0 <= current + pos < len(image_list)):
        # Out-Of-Range: no image to display
        return
    current += pos
    # set image to the image-label
    image = Image.open('./images/'+image_list[current])
    photo = ImageTk.PhotoImage(image)
    image_label['text'] = str(current+1) +". "+ image_list[current]
    image_label['image'] = photo
    image_label.photo = photo


# start GUI
move(0)
window.mainloop()