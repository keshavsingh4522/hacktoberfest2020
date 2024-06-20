check = ""
for i in range(1,1000000):
    check += str(i)

ans = 1 
ans = int(check[0])*int(check[9])*int(check[99])*int(check[999])*int(check[9999])*int(check[99999])*int(check[999999])
print(ans)