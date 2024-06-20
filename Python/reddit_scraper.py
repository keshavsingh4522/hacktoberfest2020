import requests
import csv
import time
from bs4 import BeautifulSoup


class HaikuScraper:
	"""
	This scraper is designed with the purpose of scraping Haikus (Japanese poems) from Reddit.
	"""
    def __init__(self, url: str, headers: dict):
        self.url = url
        self.headers = headers

    def make_request(self):
        time.sleep(3)
        page = requests.get(self.url, headers=self.headers)
        soup = BeautifulSoup(page.text, 'html.parser')
        return soup

    def get_next_page(self, soup: BeautifulSoup):
        time.sleep(3)
        next_button = soup.find('span', class_='next-button')
        next_page_link = next_button.find("a").attrs['href']
        return next_page_link

    def get_haikus(self, soup: BeautifulSoup):
        haikus = [str(title.text) for title in soup.find_all("a", class_="title may-blank ")]
        return haikus

    def write_haikus_to_csv(self, haikus: list):
        with open('scraped_haikus_v2.txt', 'a') as f:
            writer = csv.writer(f)
            for haiku in haikus:
              writer.writerow([haiku])
            f.close()



url = "https://old.reddit.com/r/haiku/"
# Headers to mimic a browser visit
headers = {'User-Agent': 'Mozilla/5.0'}

scraper = HaikuScraper(url, headers)
soup = scraper.make_request()

haikus = scraper.get_haikus(soup)
scraper.write_haikus_to_csv(haikus)

counter = 1

while (counter <= 2500):
  time.sleep(2)
  link = scraper.get_next_page(soup)
  print(f"Page {counter + 1}. Link {link}.")
  scraper = HaikuScraper(link, headers)
  soup = scraper.make_request()
  haikus = scraper.get_haikus(soup)
  scraper.write_haikus_to_csv(haikus)
  counter += 1