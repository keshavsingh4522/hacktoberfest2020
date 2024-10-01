def checking num
    if (num**3).to_s.end_with?(num.to_s)
    return true 
    else 
    return false
    end   
end 

puts "Type the number to check if it is a Trimorphic number: "

num=gets.to_i
puts num 
puts checking num

'''

Trimorphic Numbers
 
A trimorphic number is a number whose cube ends in the number itself. 

For example:
Input: 4
Output: true (4^3 is 64, which ends in 4)

Input: 24
Output: true (24^3 = 13824)

Input: 249
Output: true (249^3 = 15438249)

Write a program to check if the user input is a trimorphic number or not.

'''
