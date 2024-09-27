class Stack():
    def __init__(self):
        self.items = []
    def push (self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def is_empty(self):
        return len(self.items) == 0
    def peek(self):
        if not self.is_empty():
            return self.items[-1]
    def get_stack(self):
        return self.items

#[ 1, 3,2, 4]  #  input =  1 3 0 0 1 2  4
#[-1,-1,3,-1]  # 0utpt =  -1 -1 3 3 3 3 -1
def GreatestToLeft(arr):
    stack = Stack()
    ans = []
    for i in arr:
        if stack.is_empty():
            ans.append(-1)
        elif not stack.is_empty() and stack.peek()>i:
            ans.append(stack.peek())
        elif not stack.is_empty() and stack.peek()<=i:
            while  not stack.is_empty() and stack.peek()<=i:
                stack.pop()
            if stack.is_empty():
                ans.append(-1)
            else:
                ans.append(stack.peek())
        stack.push(i)
    return ans

# 2nd loop depend on i and brute force is nested for loop with O(n^2)
#  input =  1 3 0 0 1 2  4
# output =  3 4 1 1 2 4 -1
def GreatestToRight(arr):
    stack = Stack()
    ans = []
    for i in arr[::-1]:
        if stack.is_empty():
            ans.append(-1)
        elif not stack.is_empty() and stack.peek()>i:
            ans.append(stack.peek())
        elif not stack.is_empty() and stack.peek()<=i:
            while not stack.is_empty() and stack.peek()<=i:
                stack.pop()
            if stack.is_empty():
                ans.append(-1)
            else:
                ans.append(stack.peek())
        stack.push(i)
    return ans[::-1]

#  input =   1 3  0  0 1 2 4
# output =  -1 1 -1 -1 0 1 2
def SmallerToLeft(arr):
    stack = Stack()
    ans = []
    for i in arr:
        if stack.is_empty():
            ans.append(-1)
        elif not stack.is_empty() and stack.peek()<i:
            ans.append(stack.peek())
        elif not stack.is_empty() and stack.peek()>=i:
            while  not stack.is_empty() and stack.peek()>=i:
                stack.pop()
            if stack.is_empty():
                ans.append(-1)
            else:
                ans.append(stack.peek())
        stack.push(i)
    return ans
