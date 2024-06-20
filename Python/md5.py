import hashlib 

while 1:
    string = input("Enter string ")
    result = hashlib.md5(string.encode()) 
    print("The hexadecimal equivalent of hash is : ", result.hexdigest())
    if input("Want to continue? y/n : ").lower() == 'n':
        break