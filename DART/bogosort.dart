//check if two lists are not equal
bool listsAreNotEqual(l1, l2) {
  for (var pair in [
    for (int i = 0; i < l1.length; i += 1) [l1[i], l2[i]]
  ]) {
    if (pair[0] != pair[1]) {
      return true;
    }
  }
  return false;
}

//Function to sort a list using the bogosort algorithm
//The bogosort consists of shuffling a list until it is sorted
//Parameter: the list to be sorted
bogosort(list) {
  var sorted = List.from(list);
  sorted.sort();
  do {
    list.shuffle();
  } while (listsAreNotEqual(list, sorted));
  return list;
}

void main() {
  //examples
  print(bogosort([4, 2, 3]));
  print(bogosort(["foo", "bar", "barr"]));
}
