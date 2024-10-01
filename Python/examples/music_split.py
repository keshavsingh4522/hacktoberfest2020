# -*- coding: utf-8 -*-
"""
Created on Sat Apr 10 17:29:24 2021

@author: belimeio
"""

import youtube_dl 
link = input("Enter the video link:")
ydl_opts = {
    'format': 'bestaudio/best',   
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',
        'preferredquality': '192',
    }]
}

with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    info_dict = ydl.extract_info(link, download=False)
    video_title = info_dict.get('title', None)

path = f'downloads\\{video_title}.mp3'

ydl_opts.update({'outtmpl':path})

with youtube_dl.YoutubeDL(ydl_opts) as ydl:
    ydl.download([link])