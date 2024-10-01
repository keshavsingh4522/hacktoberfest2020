from TikTokApi import TikTokApi
import string
import random

def id_generator(size=8, chars=string.ascii_uppercase + string.digits):
    return ''.join(random.choice(chars) for _ in range(size))

api = TikTokApi.get_instance()

url=input("Entre com a URL: ")

video=api.get_video_by_url(url)

with open (id_generator() +".mp4",  "wb") as out:
    out.write(video)
