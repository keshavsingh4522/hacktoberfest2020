## Wiki Scrapper
Extracts information from wikipedia pages.

Reference API - [PyPi - Wikipedia](https://pypi.org/project/wikipedia/)

### Usage
```
cd Python/Wiki_Scrapper
pip install -r requirements.txt

# Ping wikipedia to get related topics
py wiki.py --ping "query"

# Get summary for a particular topic
py wiki.py --gist "query"

# Get wikipedia page information for a particular topic
py wiki.py --page "query"

# Set language preference for a search instance
py wiki.py --lang "en"


P.S - All arguments can be used simultaneously

Note: This script is for educational purposes only. Web Scrapping isn't actually allowed by some websites as per their privacy policy
```
