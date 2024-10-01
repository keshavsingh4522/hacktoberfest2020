def romanToInt(s: str) -> int:
    map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    sum = 0
    i = 0
    while i < len(s):
        try:
            curr = map[s[i]]
            next = map[s[i + 1]]
            if curr < next:
                sum += next - curr
                i += 2
            else:
                sum += curr
                i += 1
        except:
            sum += curr
            break
    return sum


print(romanToInt("MCMXCIV"), "A.D")
print(romanToInt("XCI"))
