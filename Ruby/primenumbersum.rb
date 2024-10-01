num = 1
last = 100

while (num <= last)
  condition = true
  x = 2
  while (x <= num / 2)
    if (num % x == 0)
      condition = false
      break
    end 
    x = x + 1  
  end
  primes = [] # Here

  if condition     
    puts num.to_s
    primes << num.to_s  
  end
  num = num + 1
end

puts primes.inject(:+) 
