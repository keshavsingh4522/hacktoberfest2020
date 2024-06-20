def score_of_name(name):
    sum = 0
    for character in name:
        if character != "\"":
            sum += ord(character) - ord('A') + 1
    return sum



f = open("names.txt","r")
final_ans = 0
names = f.readline().split(',')
names.sort()
for key,elem in enumerate(names):
    final_ans += score_of_name(elem)*(key+1)
print(final_ans)