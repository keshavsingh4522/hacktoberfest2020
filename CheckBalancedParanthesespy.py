def checkBalancedParentheses(s):
	'''
	Checks if parentheses are balanced. Takes a string as an input.
	'''
	stack = []
	for i in range(len(s)):
		if s[i] == '[' or s[i] == '{' or s[i] == '(':
			stack.append(s[i])
		else:
			if not stack:
				return False
			q = stack.pop()
			if s[i] == '[' and q != ']':
				return False
			elif s[i] == ' (' and q != ')':
				return False
			elif s[i] == '{' and q != '}':
				return False
	if stack:
		return False
	else:
		return True

s = "[{}{}(]"			# returns False
print(checkBalancedParentheses(s))

s1 = "{([{[]}])}"		# returns True
print(checkBalancedParentheses(s1))
