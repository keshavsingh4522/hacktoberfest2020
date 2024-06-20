import hashlib
import itertools

# list of character to make some combination
stringKey = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'

# hashedMessage is 'abcd'
hashedMessage = 'e2fc714c4727ee9395f324cd2e7f331f' 

# if your hashedMessage too complex, it may take for a long time
for i in range(len(stringKey)):
  pm = itertools.combinations(stringKey, i)
  for item in pm: 
    combinationString = ''.join(item)
    hashedString = hashlib.md5(combinationString.encode()).hexdigest()
    if hashedString == hashedMessage:
      print(f'The Message is : {combinationString}')
