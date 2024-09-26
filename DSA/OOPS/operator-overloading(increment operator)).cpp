#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

class complex{

public:
    int kg=0;

    complex operator ++(){
        ++kg;
    }

};

int main()
{
    complex obj1;
    ++obj1;
    ++obj1;
    ++obj1;
    cout<<obj1.kg;
}
