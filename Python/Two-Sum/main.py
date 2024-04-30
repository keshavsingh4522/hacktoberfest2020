def two_sum(list, k):
  # Fill this in.
  for value in list:
    for value2 in range(list.index(value), len(list)):
      if(value + list[value2] == k):
        return True;
  return False

print (two_sum([4,7,1,-3,2], 5))
# True
