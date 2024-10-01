matrix = []
for i in range(26):
    temp = []
    for j in range(26):
        tempVal = i+j+65
        if tempVal <= 90:
            temp.append(chr(tempVal))
        else:
            tempVal = (tempVal % 65) + 39
            temp.append(chr(tempVal))
    matrix.append(temp)
print("================")
print("Vigenere Table")
print("================")
for rows in matrix:
    print(rows)

cipherText = ''
auto = False
plainText = list(
    (input("\nEnter Your Plain Text :: ").upper()).replace(" ", ""))
key = list((input("Enter Your Key :: ").upper()).replace(" ", ""))

c = 0
while len(key) != len(plainText):
    auto = True
    key.append(plainText[c])
    c += 1
if auto == True:

    print("Auto Key Generated: ", end="")
    print(''.join(map(str, key)))

for i in range(len(plainText)):
    pNo, kNo = ord(plainText[i])-65, ord(key[i])-65
    cipherText += matrix[kNo][pNo]

print("\nCipher Text:", cipherText)
