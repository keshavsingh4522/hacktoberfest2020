def bad_chars(needle):

    bad_char = [-1] * 256

    for i, v in enumerate(needle):
        bad_char[ord(v)] = i

    return bad_char


def search(haystack, needle):
    haystack_size = len(haystack)
    needle_size = len(needle)

    if haystack == needle:
        return 0
    elif haystack_size < needle_size:
        return -1

    shift = 0
    bad_char = bad_chars(needle)

    while shift <= haystack_size - needle_size:
        last = needle_size - 1

        while last >= 0 and needle[last] == haystack[shift + last]:
            last -= 1

        if last < 0:
            return shift
        else:
            bad = bad_char[ord(haystack[shift + last])]
            shift += max(1, last - bad)
    return -1


haystack = "mississippi"
needle = "issip"
print(search(haystack, needle))
