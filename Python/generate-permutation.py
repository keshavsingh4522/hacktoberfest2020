def permute(s, l, r):
    if l == r:
        print("".join(s))
    else:
        for i in range(l, r):
            s[l], s[i] = s[i], s[l]
            permute(s, l + 1, r)
            s[l], s[i] = s[i], s[l]


s = list("abcd")
permute(s, 0, len(s))
