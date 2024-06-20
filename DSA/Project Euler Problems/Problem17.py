import num2words # Install Module using pip install num2words
def charactercount(str):
    return len(list(filter(lambda x:x.isalpha(),str)))
ans = 0
for i in range(1,1001):
    ans += charactercount(num2words.num2words(i))
print(ans)