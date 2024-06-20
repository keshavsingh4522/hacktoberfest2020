triangle = set()
pentagonal = set()
hexagonal = set()

for i in range(1,100000):
    triangle.add(i*(i+1)/2)
    pentagonal.add(i*(3*i-1)/2)
    hexagonal.add(i*(2*i-1))

i = 0
for elem in triangle:
    if elem != 1 and elem in pentagonal and elem in hexagonal:
        print(elem)
        i += 1
    if i == 2:
        break
