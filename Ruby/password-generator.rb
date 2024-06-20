# Password Generator - Ran Crump
# Run the source code here: https://replit.com/languages/ruby

upper_alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
lower_alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
numbers = ['0','1','2','3','4','5','6','7','8','9']
symbols = ['*','/','.','?','[]',';','@','!','$','#','^','%','&','+','-']

puts ("Use Symbols? (y/n)")
use_symbols = gets.chomp

possibleCharacters = [];

if (use_symbols=='y' || use_symbols=='Y')
	puts "Using special symbols"
    possibleCharacters.concat(upper_alphabet)
    possibleCharacters.concat(lower_alphabet)
    possibleCharacters.concat(numbers)
    possibleCharacters.concat(symbols)
else
	puts "Not using special symbols"
    possibleCharacters.concat(upper_alphabet)
    possibleCharacters.concat(lower_alphabet)
    possibleCharacters.concat(numbers)    
end

puts ("How long should the password be?")
password_length = gets.to_i

i = 0
password = ''
for i in 0..password_length
    password += possibleCharacters[rand(possibleCharacters.length)]
end

puts password