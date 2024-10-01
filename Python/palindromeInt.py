sen = input("Enter the word")
if " " in sen:
  print("PLEASE ENTER A WORD, NOT A SENTENCE")
else:
  if len(sen)%2 == 0:
    if (sen[:(len(sen)//2)])[::-1] == sen[(len(sen)//2):]:
      print("it is a palindrome")
    else:
      print("it is not a palindrome")
  else:
    if (sen[:len(sen)//2])[::-1] == sen[(len(sen)//2)+1:]:
      print("it is a palindrome")
    else:
      print("it is not a palindrome")