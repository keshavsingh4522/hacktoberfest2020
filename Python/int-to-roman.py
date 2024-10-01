def intToRoman(num: int) -> str:
    map = { 1000: "M", 900: "CM", 500: "D", 400: "CD", 100: "C", 90: "XC", 50: "L", 40: "XL", 10: "X", 9: "IX", 5: "V", 4: "IV", 1: "I"}
    roman = ""
    for k in map:
        d = num // k
        roman += map[k] * d
        num %= k
        if not num:
            return roman


print(31, intToRoman(31))
print(48, intToRoman(48))
print(1994, intToRoman(1994))
print(3999, intToRoman(3999))
