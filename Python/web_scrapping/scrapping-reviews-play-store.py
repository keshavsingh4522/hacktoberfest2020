# Install google-play-scraper using --
# !pip install google-play-scraper
# we will be scrapping reviews from zoho app.
from google_play_scraper import app, Sort, reviews_all
import pandas as pd
import numpy as np
zoho_reviews = reviews_all(
    'com.zoho.mail', sleep_milliseconds=0,  # defaults to 0
    lang='en',  # defaults to 'en'
    country='us',  # defaults to 'us'
    sort=Sort.NEWEST,  # defaults to Sort.MOST_RELEVANT
)
print(zoho_reviews)
