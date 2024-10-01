import pyshorteners as sh

link = 'https://example.com/assets/category_B/subcategory_C/Foo'

s = sh.Shortener()
url = (s.tinyurl.short(link))

print(url)
