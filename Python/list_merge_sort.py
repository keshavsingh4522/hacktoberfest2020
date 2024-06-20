l1 = [1, 2, 4, 45]
l2 = [1, 3, 5, 6, 8, 10]

res = []
while l1 and l2: # Both lists contain items
    if l1[0] > l2[0]: # L1 first item > L2 first item ->
        res.append(l2.pop(0)) # then remove and append L2 first item
    elif l1[0] < l2[0]: # L1 first item < L2 first item ->
        res.append(l1.pop(0)) # then remove and append L1 first item
    else: # Items are equal -> 
        res.append(l1.pop(0)) # append both 
        res.append(l2.pop(0))
    print(l1, l2)
if l1: # There will always be some elements left, so find which list has them and ADD them to result
    res += l1
elif l2:
    res += l2

print(res)
