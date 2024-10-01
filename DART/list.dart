main(List<String> arguments) {
  //create list kosong with int data type
  List<int> myList = [];
  //create list with int data type
  List<int> list = [1, 2, 3];

  print(list[0]);
  print(list[1]);
  print(list[2]);

  //print all list value using for loop
  print("Print using for loop: ");
  for (int i = 0; i < list.length; i++) {
    print(list[i]);
  }

  // print all list value using for in
  print("Print using for in: ");
  for (int bilangan in list) {
    print(bilangan);
  }

  //print all list value using for each
  print("Print using for each: ");
  list.forEach((bilangan) {
    print(bilangan);
  });

  //basic operation on list
  //add element
  myList.add(10);
  //add list of value into list
  myList.addAll(list);
  //another way
  myList.addAll([6,7,8]);
  //add value at specific index
  myList.insert(1, 25);
  //add multiple value to list start at spesific index
  myList.insertAll(3, [30, 40, 20]);

  print("before removing value: ");
  myList.forEach((element) {
    print(element);
  });

  //remove value frol list
  myList.remove(20);
  //remove value from list at spesific index
  myList.removeAt(1);
  //remove last value from list
  myList.removeLast();
  //remove  value at spesific range
  myList.removeRange(2, 6);

  //remove value using where
  //remove angka ganjil
  myList.removeWhere((number) => number % 2 != 0);

  print("After removing some value: ");
  myList.forEach((element) {
    print(element);
  });

  //menggunakan fungsi contains
  if (myList.contains(6)) {
    print("6 found");
  }

  myList.addAll([6,7,8]);

  print("Print myList: ");
  myList.forEach((element) {
    print(element);
  });

  //sublist
  List<int> sublist = [];
  print("Print sublis start only: ");
  sublist = myList.sublist(1);
  //print sublist with start index only
  sublist.forEach((element) {
    print(element);
  });

  //sublist with start and end index
  sublist = myList.sublist(1,4);
  print("print ublist start and end: ");
  sublist.forEach((element) {
    print(element);
  });

  //remove all value on list
  sublist.clear();
  print("Print sublist after clear(): ");
  sublist.forEach((element) {
    print(element);
  });

  //sort all element
  sublist.addAll(myList);
  print("Print sublist after sorted: ");
  sublist.sort();
  sublist.forEach((element) {
    print(element);
  });
}