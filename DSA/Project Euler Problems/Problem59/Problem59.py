import string
import copy

a = [elem for elem in string.ascii_lowercase]
f = open("p059_cipher.txt",'r')
w = open("generatemessage.txt",'w')
data = [int(elem) for elem in f.readline().split(',')]


storeKeys = []

def generate_keys(key,length = 3):
    if len(key) == length:
        storeKeys.append(key)
        return
    for i in range(len(a)):
        temp = copy.deepcopy(key)
        temp.append(a[i])
        generate_keys(copy.deepcopy(temp))
        

generate_keys([])

for elem in storeKeys:
    plaincipher = []
    sum = 0
    for i in range(len(data)):
        plaincipher.append(chr(data[i]^ord(elem[i%3])))
        sum += data[i]^ord(elem[i%3])

    w.write(''.join(plaincipher))
    w.write('  '+''.join(elem))
    w.write('  '+str(sum))
    w.write('\n')

# Key is exp