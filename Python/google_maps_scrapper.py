from time import sleep, time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from bs4 import BeautifulSoup
import json, os

start_time = time()
browser = webdriver.Chrome()
google_maps_url = "https://www.google.de/maps/@19.57,79.18,12z?hl=en"

browser.get(google_maps_url)

# wait website to load
sleep(2)
main_page = browser.current_window_handle

# enter popup frame 
browser.switch_to.frame(0)

# close popup 
popup_close_btn = browser.find_element_by_id('introAgreeButton')
popup_close_btn.click()
sleep(0.5)

# exit popup frame
browser.switch_to.window(main_page)
sleep(0.5)

# search something
search_input = browser.find_element_by_id('searchboxinput')
search_input.send_keys(Keys.CLEAR)
search_input.send_keys('Restaurants')
search_input.send_keys(Keys.ENTER)


businesses = list()

def get_search_results():
    global businesses
    # wait for results
    sleep(5)

    search_results_parent_div = browser.find_element_by_xpath('//div[@aria-label="Results for Restaurants"]')
    search_results = search_results_parent_div.find_elements_by_xpath('//div[@class="section-result"]')
    
    for search_result in search_results:
        raw_html = search_result.get_attribute('innerHTML')
            
        soup = BeautifulSoup(raw_html)
        
        title = soup.find(class_="section-result-title").text
        business_type = soup.find(class_="section-result-details").text
        location_soup = soup.find(class_="section-result-location")
        location = location_soup.text if location_soup else None
        rating_soup = soup.find(class_="cards-rating-score")
        rating = float(rating_soup.text) if rating_soup else None
            
        business = {
            'title': title,
            'type': business_type,
            'location': location,
            'rating': rating
        }
        
        businesses.append(business)

# get first page
get_search_results()


# get next page
next_button = browser.find_element_by_xpath('//button[@aria-label=" Next page "]')

total_pages = 1
max_pages = 0


while(next_button and next_button.is_enabled() and ( total_pages < max_pages  if max_pages > 0 else True)):
    # press next button
    next_button.click()
    
    # get results
    get_search_results()    
    total_pages += 1


# dump data

file_name = os.path.dirname(os.path.realpath(__file__)) + '/data.json'

with open(file_name, 'w+') as json_file: 
    json.dump(businesses, json_file)
    
    
# close the window
browser.close()

print("Total businesses: {}".format(len(businesses)))
print("Total pages: {}".format(total_pages))
print("Max pages: {}".format(max_pages))


end_time = time()
elapsed_secs = end_time - start_time
print("✅ Completed in {} seconds!".format(elapsed_secs))



# fetch data -> RAW DATA

# clean data -> BRING IT TO single FORMAT

# dump data -> JSON / CSV