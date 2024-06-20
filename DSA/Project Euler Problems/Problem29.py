data = set()
for i in range(2,101):
    for j in range(2,101):
        data.add(i**j)
print(len(data))