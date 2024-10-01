# the problem statement can be found here:https://leetcode.com/problems/integer-to-roman/


def intToRoman(num: int) -> str:
        # Roman numerals that appear in each digit
        digit_romans = [
            ['I', 'V', 'X'],    # digit 0 numerals
            ['X', 'L', 'C'],    # digit 1 numerals
            ['C', 'D', 'M'],    # digit 2 numerals
            ['M', '', '']       # digit 3 numerals
        ]
        # Indices in digit_romans[i] for digits 1-9
        roman_numerals = [
							# 0 -- skip
            (0,),           # 1
            (0, 0),         # 2
            (0, 0, 0),      # 3
            (0, 1),         # 4
            (1,),           # 5
            (1, 0),         # 6
            (1, 0, 0),      # 7
            (1, 0, 0, 0),   # 8
            (0, 2)          # 9
        ]
        
        # Build numeral from highest digit to lowest
        numeral = ""
        # Start at highest digit available, work down to 0th digit
        highest_dig_index = int(math.log10(num))
        for i in range(highest_dig_index, -1, -1):
            # ith digit
            d = (num // 10**i) % 10
            
            # d==0 has no output
            if d > 0:
				# Characters used in this digit
                r = digit_romans[i]
				# Character patterns for any digit
                n = roman_numerals[d - 1]
				
                numeral += "".join(r[j] for j in n)
        
        return numeral
