import array as ar

num = ar.array('i', [1, 2, 3])

num.append(4)
print(num)    

num.extend([5, 6, 7])
print(num)

ln=len(num)
print(ln) #length 

num[0] = 0  #changing first element  
print(num) 

num.append(4) #appending 4 to array
print(num)    

num.extend([5, 6, 7]) #extending numbers with 5,6,7
print(num)

num.insert(1,9)

for x in num:
 print(x)

num.remove(7)

for x in num:
 print(x)