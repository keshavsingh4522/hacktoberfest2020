f = open("p079_keylog.txt",'r')



digits_before = {}
digits_after = {}
for i in range(0,10):
    digits_before[i] = set()
    digits_after[i] = set()

for elem in f.readlines():
    data = [int(elem) for elem in elem[:-1]]
    for i in range(len(data)):
        for j in range(i + 1, len(data)):
            digits_after[data[i]].add(data[j])
        for k in range(0,i):
            digits_before[data[i]].add(data[k])

print('Digits Before')
for digit, values in zip(digits_before.keys(),digits_before.values()):
    print(digit, values)

print('\n\n Digits After')
for digit,values in zip(digits_after.keys(),digits_after.values()):
    print(digit,values)


# Derived Answer from output : 73162890