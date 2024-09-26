// Problem Statement:
// Write a program to find a unique number in an array where all numbers except one, are present thrice.


/* Logic:
1. Maintain an array of 64 size which will store the number of times ith
bit has occurred in the array.
2. Take the modulo of each element of this array with 3. 
Resultant array will represent the binary representation of the unique number.
3. Convert that binary number to decimal number and output it.
*/


// Time Complexity: O (64*n) = O(n) 
// Space Complexity: An integer array with 64 elements - 64*4 = 256 bits = 32 bytes


// Solution:

#include <iostream>
using namespace std;

bool getBit ( int n , int pos ) {
  return (( n & ( 1 << pos )) != 0 );
}

int setBit ( int n , int pos ) {
  return ( n | ( 1 << pos ));
}

int unique ( int arr [], int n ) {
  int result = 0 ;
  for ( int i = 0 ; i < 64 ; i++) {
    int sum = 0 ;
    for ( int j = 0 ; j < n ; j ++) {
      if ( getBit ( arr [ j ], i )) {
        sum ++;
      }
    }
    if ( sum % 3 != 0 ) {
      result = setBit ( result , i );
    }
  }
  return result ;
}

//  Main Program
int main () {
  int arr [] = { 1 , 2 , 3 , 4 , 1 , 2 , 3 , 1 , 2 , 3 };
  cout << unique ( arr , 10 ) << endl ;
  return 0
}
