#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
string print(int h){
    if(h<10) return "0"+to_string(h);
    else return to_string(h);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int h , m , s;
    string str;
    char r;
    cin >> h >> r >> m >> r >> s >> str;
    if(str=="PM" && h!=12) h = h+12;
    else if(str=="AM" && h==12) h = (h+12)%24;
    cout << print(h) << ":" << print(m) << ":" << print(s) << endl;
    return 0;
}