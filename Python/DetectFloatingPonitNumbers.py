from re import match, compile

pattern = compile('^[-+]?\d*\.\d+$')
for _ in range(int(input())):
    print(bool(pattern.match(input())))
