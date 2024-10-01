#include <set>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    std::set<int> b;
    std::vector<int> a{1, 2, 3, 5, 5};
    cout << "data in vector:";
    for(auto i: a)
    {
        cout <<  i << ",";
        b.emplace(i);
    }
    cout << std::endl;

    cout << "data in set:";
    for(auto i: b)
    {
        cout <<  i << ",";
    }
    cout << std::endl;
}
