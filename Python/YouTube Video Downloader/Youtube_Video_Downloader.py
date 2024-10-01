from pytube import YouTube, exceptions
import logging
import requests
import urllib.parse
import urllib.request

# Enable Logger
logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s', level=logging.WARN)
logger = logging.getLogger(__name__)


def download_video(link: str) -> str:
    '''Try to download video in Highest Res. and return saved path'''
    try:
        yt = YouTube(link)  # initializing YouTube object
        print(f'Title: {yt.title}')
        print(f'Channel: {yt.author}')
        print(f'Duration: {yt.length}')
        path = yt.streams.get_highest_resolution().download('downloads')
        return path

    except exceptions.RegexMatchError:
        logger.error(msg='Not a Valid YouTube URL')
        return None

    except exceptions.LiveStreamError:
        logger.error(msg='Live Streams Cannot be Downloaded')
        return None

    except exceptions.VideoUnavailable:
        logger.error(msg='Video is Unavailable')
        return None

    except exceptions.HTMLParseError:
        logger.error(msg='Given URl could not be Parsed')
        return None

def name_url(name):  
        music_name = name
        query_string = urllib.parse.urlencode({"search_query": music_name})
        formatUrl = urllib.request.urlopen("https://www.youtube.com/results?" + query_string)
        search_results = re.findall(r"watch\?v=(\S{11})", formatUrl.read().decode())
        clip = requests.get("https://www.youtube.com/watch?v=" + "{}".format(search_results[0]))
        clip2 = "https://www.youtube.com/watch?v=" + "{}".format(search_results[0])
        return clip2
    
if __name__ == '__main__':
    print(" Enter 1 to Download Viedo By Link ")
    print(" Enter 2 to Download Viedo By Name ")
    num = int(input((" Please Enter 1 or 2")))
    if(num == 1):
        link = input('Enter a valid YouTube Link : ')
        save_path = download_video(link)
        if(save_path):
            print(f'Video Downloaded at {save_path}')
        else:
            print('Some Error occured, check Log for more details')
    else if(num == 2):
        name = input("Enter The Viedo Name :)
        y=YouTube(name_url(name))
        save_path = download_video(y)
        if(save_path):
            print(f'Video Downloaded at {save_path}')
        else:
            print('Some Error occured, check Log for more details')
    else:
        print("Please Enter The Correct Options")
        
