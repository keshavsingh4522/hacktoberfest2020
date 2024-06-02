#Beginner's web scraper using beautiful soup library

import requests
import bs4
ex_url="http://books.toscrape.com/catalogue/page-{}.html" #dummy website for web scraping
x=1
while (x<20): #20 is the number of pages on the website
    cur_page=ex_url.format(x)
    res= requests.get(cur_page)
    soup=bs4.BeautifulSoup(res.text,"lxml")
    prod=soup.select('.product_pod')
    ctr=0
    for user in (prod):
        
        if(user.select('.star-rating.Three')==[]): #three- starred items
            pass
        else:
            print(user.select('a')[1]['title']) #print the name of the product
    x=x+1   
