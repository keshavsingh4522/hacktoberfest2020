from tkinter import*
from PIL import ImageTk, Image
import sys

def youtube():
	import yt_video_downloader

root = Tk()
root.title("Select Any of the Choice")
root.geometry("500x500")
root.resizable(0, 0)

# creating frames
youtube_frame = Frame(root, width=500, height=250, bd=0, bg='black', relief=GROOVE)
youtube_frame.pack()

local_library_frame = Frame(root, width=500, height=250, bd=0, bg='yellow', relief=GROOVE)
local_library_frame.pack()


# creating buttons to add them in their respective frames

yt_btn = Image.open("youtube.jpg")
yt_btn_resize = yt_btn.resize((500, 250), Image.ANTIALIAS)
btn = ImageTk.PhotoImage(yt_btn_resize)
youtube_btn = Button(youtube_frame, image=btn, command=youtube)
youtube_btn.pack()

local_library_btn = Button(local_library_frame, width=500, height=250, text="Play from Local Library", font="Corbel 30 bold")
local_library_btn.pack()

root.mainloop()