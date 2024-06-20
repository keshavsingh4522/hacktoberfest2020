from tkinter import*
import pafy
import vlc
import requests
import re
import tkinter.messagebox as tmsg
import threading
from tkinter import filedialog


def download():

	try:
		url_part = get_video()

		url = "www.youtube.com" + url_part

		video = pafy.new(url)

		# playing video in best quality
		best = video.getbest(preftype="mp4")

		best.download()
		tmsg.showinfo("Success !", "Your video is download !")

	except Exception as e:
		tmsg.showerror("Error!", "Can't Download the video")


def start():
	t1 = threading.Thread(target=play_video, daemon=True)
	t1.start()


def open_local():
	video = filedialog.askopenfilename()

	global media

	media = vlc.MediaPlayer(video)
	
	# changing the audio of the video
	media.video_set_scale(0.7)

	# creating canvas to play the video 
	play_screen = Canvas(main_frame, width=500, height=300)
	play_screen.pack()

	# media.video_set_scale(0.2)

	media.set_hwnd(play_screen.winfo_id())
	media.play()


def play_video():

	global media

	try:
		url_part = get_video()
		url = "www.youtube.com" + url_part
		video = pafy.new(url)

		# playing video in best quality
		best = video.getbest()

		media = vlc.MediaPlayer(best.url)
		
		# changing the audio of the video
		media.video_set_scale(0.7)

		# creating canvas to play the video 
		play_screen = Canvas(main_frame, width=500, height=300)
		play_screen.pack()

		# media.video_set_scale(0.2)

		media.set_hwnd(play_screen.winfo_id())
		media.play()

	except Exception as e:
		tmsg.showerror("Error !", "Can't play video because of some issue :/")

	# clearing the search box
	search_variable.set(" ")


def resume_vid():
	try:	
		global media
		media.play()
		pause_btn['text'] = "Pause"
		pause_btn['fg'] = "White"

	except Exception as e:
		tmsg.showerror("Error!", "Video is not started yet !")

def pause_vid():
	try:	
		global media
		media.set_pause(1)
		pause_btn['text'] = "Paused"
		pause_btn['fg'] = "yellow"

	except Exception as e:
		tmsg.showerror("Error!", "Video is not started yet !")

def get_page(url):
	r = requests.get(url)
	return r.text

def get_video():
	page = get_page(f"https://www.youtube.com/results?search_query={search_variable.get()}")

	# finding the links of all the videos ( using re ) from that opened page
	q = re.findall("/watch\?v=[a-zA-Z0-9]{11}", page)
	length = len(q)

	original_vid = ""

	for i in range(length):
		original_vid = q[0] # assigning the 0th index cuz it is most matched search

	return original_vid

def del_canvas():

	try:	
		global media
		media.stop()

		# clearing out the canvas frame
		for widgets in main_frame.winfo_children():
			widgets.destroy()

	except Exception as e:
		tmsg.showerror("Error !", "There is no canvas to delete !")


if __name__ == '__main__':
	
	# customizing the window
	root = Tk()
	root.title("Download YouTube Video")
	root.geometry("500x520")
	root.resizable(0,0)


	# creating frames

	header_frame = Frame(root, width=500, height=150, relief=SUNKEN, bg="gray")
	header_frame.pack()

	main_frame = Frame(root, width=500, height=300, relief=SUNKEN, bg="black")
	main_frame.pack()

	footer_frame = Frame(root, width=500, height=50, relief=SUNKEN)
	footer_frame.pack()

	left_frame = Frame(footer_frame, width=150, height=50, bg="black")
	left_frame.pack(side=LEFT, anchor=W)

	right_frame = Frame(footer_frame, width=150, height=50, bg="blue")
	right_frame.pack(side=RIGHT, anchor=E)

	center_frame = Frame(footer_frame, width=150, height=50, bg="yellow")
	center_frame.pack(side=BOTTOM)

	# header_left_frame = Frame(header_frame, width=10, height=10, bg="yellow", bd=6)
	# header_left_frame.pack(side=LEFT, anchor=SW)


	# styling header frame
	Label(header_frame, text="Search the Video", font="lucida 15 bold", bg="gray").pack()
	search_variable = StringVar()
	Entry(header_frame, textvar=search_variable, width=200, justify="center", relief=GROOVE, bd=2, font='Corbel 20 bold').pack(pady=10, padx=10)
	search_btn = Button(header_frame, text="Search", bg="black", fg="white", font='lucida 15 italic', command=start)
	search_btn.pack(pady=10)


	# syling footer frame
	pause_btn = Button(left_frame, height=50, width=10, text="Pause", fg="white", bg="black", command=pause_vid)
	pause_btn.pack()

	resume_btn = Button(center_frame, height=50, width=10, text="Resume", fg="white", bg="black", command=resume_vid)
	resume_btn.pack()

	dwnld_btn = Button(right_frame, height=50, width=10, bg='green', fg='red', text="Download", bd=2, command=download)
	dwnld_btn.pack()

	local_btn = Button(header_frame, bg='green', fg='red', text="Import Local", bd=2, command=open_local)
	local_btn.pack(padx=50, pady=5, side=RIGHT)

	del_btn = Button(header_frame, bg='green', fg='red', text="Stop", bd=2, command=del_canvas)
	del_btn.pack(side=LEFT, padx=20)

	root.mainloop()