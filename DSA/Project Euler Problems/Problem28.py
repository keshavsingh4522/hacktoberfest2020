def form_spiral(num):
    data = []
    for i in range(num):
        temp = []
        for j in range(num):
            temp.append(0)
        data.append(temp.copy())
    curr_count =num*num
    dir = 'l'
    i,j = (0,num-1)
    while curr_count >1:
        data[i][j] = curr_count
        if dir == 'l' and j-1 >= 0 and data[i][j-1] == 0:
            j = j-1
            curr_count -=1
        elif dir == 'r' and j+1 < num and data[i][j+1] == 0:
            j = j+1
            curr_count-=1
        elif dir == 'd' and i+1 < num and data[i+1][j] == 0:
            i = i+1
            curr_count-=1
        elif dir == 'u' and i-1 >= 0 and num and data[i-1][j] ==0:
            i = i-1
            curr_count-=1
        elif dir == 'l':
            dir = 'd'
        elif dir == 'd':
            dir = 'r'
        elif dir == 'r':
            dir = 'u'
        elif dir == 'u':
            dir = 'l'
    data[i][j] = curr_count
        
    return data


def find_diagonal(data):
    sum = 0
    for i in range(len(data)):
        sum += data[i][i]
        sum += data[i][len(data)-i-1]
    return sum-1

print(find_diagonal(form_spiral(1001)))