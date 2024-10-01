#include <bits/stdc++.h>
using namespace std;
bool calc_parity(int N) {
   int y;
   y= N ^ (N >> 1);
   y = y ^ (y >> 2);
   y = y ^ (y >> 4);
   y = y ^ (y >> 8);
   y = y ^ (y >> 16);
   //checking the rightmost bit
   if (y & 1)
      return 1;
   return 0;
}
int main() {
   int n=1345;
   int result = calc_parity(n);
   if(result==1)
      cout << "Odd Parity" << endl;
   else
      cout << "Even Parity" << endl;
   return 0;
}
