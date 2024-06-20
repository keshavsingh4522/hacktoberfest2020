# @param {String} s
# @return {Integer}
def length_of_last_word(s)
    n = s.length() - 1
    len = 0
    while s[n] !=' '
        len = len + 1
        n = n -1
    end
    return len 
end
res = length_of_last_word("Hello Hacktoberfest!")
puts(res)