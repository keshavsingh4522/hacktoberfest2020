import tkinter as tk
from PIL import Image, ImageTk

# create instance
window = tk.Tk()
# set default window size
window.geometry("850x550")
# set min window size
window.minsize(700, 400)
# set max window size
window.maxsize(1000, 700)
# add a title
window.title("ImageGallery")

# Add header
tk.Label(window, 
    compound=tk.TOP, 
    text='---- Image Gallery ----',
    pady=20, # padding Vertical
    font=("Courier", 15, "bold") # change the font OR "Courier  18 bold"
).pack()

# Add a frame
frame = tk.Frame(window)
frame.pack(anchor=tk.CENTER)

# define image_list
image_list = ['anime.png', 'panda_face.png', 'dog.png', 'shoepping.png', 
            'color_palette.png', 'android.png']

# open image
image1 = Image.open('./images/' + image_list[0])
photo1 = ImageTk.PhotoImage(image1)

image2 = Image.open('./images/' + image_list[1])
photo2 = ImageTk.PhotoImage(image2)

image3 = Image.open('./images/' + image_list[2])
photo3 = ImageTk.PhotoImage(image3)

image4 = Image.open('./images/' + image_list[3])
photo4 = ImageTk.PhotoImage(image4)

image5 = Image.open('./images/' + image_list[4])
photo5 = ImageTk.PhotoImage(image5)

image6 = Image.open('./images/' + image_list[5])
photo6 = ImageTk.PhotoImage(image6)

# Add image-label inside frame
tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[0],
    image=photo1,
    width=300, height=300
).grid(row=1, column=1)

tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[1],
    image=photo2,
    width=300, height=300
).grid(row=1, column=2)

tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[2],
    image=photo3,
    width=300, height=300
).grid(row=1, column=3)

tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[3],
    image=photo4,
    width=300, height=300
).grid(row=2, column=1)

tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[4],
    image=photo5,
    width=300, height=300
).grid(row=2, column=2)

tk.Label(
    master=frame, # attach label to the frame
    compound=tk.TOP,
    text=image_list[5],
    image=photo6,
    width=300, height=300
).grid(row=2, column=3)


window.mainloop()