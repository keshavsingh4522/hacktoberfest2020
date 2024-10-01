#include <iostream>

using namespace std;

int mySqrt(long x) {
  long root = x;
  while (root * root > x) {
    root += (x / root);
    root /= 2;
  }
  return root;
}

int main() {
  cout << mySqrt(144) << endl;
  cout << mySqrt(214739560) << endl;
}
