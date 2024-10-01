=begin 
Ruby program to print Fibonacci series 
without recursion
=end

first=0
second=1
nextterm=0

puts "Enter the number of terms:-"
n=gets.chomp.to_i

puts "The first #{n} terms of Fibonacci series are:-"
c=1
while(c<=n+1)
	if(c<=1)
		nextterm=c
	else
		puts nextterm
		nextterm=first+second
		first=second
		second=nextterm
	end
	c+=1
end
