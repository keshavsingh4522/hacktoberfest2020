import calendar

print(calendar.calendar(1901))
x = calendar.Calendar()
ans = 0
for i in range(1901,2001):
    for j in range(1,13):
        if x.monthdayscalendar(i,j)[0][6] == 1:
            ans+= 1
print(ans)

