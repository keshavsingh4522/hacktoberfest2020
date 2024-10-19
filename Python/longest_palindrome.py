def longest_palindrome(s):
    if not s:
        return ""

    # Preprocess the string
    processed = '#' + '#'.join(s) + '#'
    n = len(processed)
    palindrome_lengths = [0] * n
    center = right = 0

    for i in range(n):
        if i < right:
            mirror = 2 * center - i
            palindrome_lengths[i] = min(right - i, palindrome_lengths[mirror])

        # Attempt to expand palindrome centered at i
        while (i + 1 + palindrome_lengths[i] < n and 
               i - 1 - palindrome_lengths[i] >= 0 and
               processed[i + 1 + palindrome_lengths[i]] == processed[i - 1 - palindrome_lengths[i]]):
            palindrome_lengths[i] += 1

        # If palindrome centered at i expands past right,
        # adjust center based on expanded palindrome
        if i + palindrome_lengths[i] > right:
            center, right = i, i + palindrome_lengths[i]

    # Find the maximum element in palindrome_lengths
    max_length, max_center = max((length, i) for i, length in enumerate(palindrome_lengths))
    start = (max_center - max_length) // 2
    return s[start:start + max_length]

def main():
    user_input = input("Enter a string to find the longest palindrome: ")
    result = longest_palindrome(user_input)
    print(f"The longest palindrome sequence is: {result}")

if __name__ == "__main__":
    main()
