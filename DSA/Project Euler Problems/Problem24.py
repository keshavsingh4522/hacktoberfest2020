from itertools import permutations
ans = [''.join(p) for p in permutations('0123456789')]
print(ans[999999])