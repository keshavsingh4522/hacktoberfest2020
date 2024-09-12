# Calculates a^b
def power(a, b):
  if b == 0:
    return 1
  b -= 1
  return a*power(a, b)

x = int(input())
y = int(input())

print(power(x, y))
