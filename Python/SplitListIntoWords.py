# Python3 code to demonstrate working of
# Split each word into percent segment in list
# Using split() + len() + slice + loop

# initializing string
test_str = 'geeksforgeeks is best for all geeks and cs students'

# printing original string
print("The original string is : " + str(test_str))

# initializing percent split
per_splt = 50

test_str = test_str.split()
res = ''
for ele in test_str:
	prop = int((per_splt/100) * len(ele))
	new_str1 = ele[:prop]
	new_str2 = ele[prop:]
	res += new_str1 + " " + new_str2 + " "
	
# printing result
print("Segmented words : " + str(res))
