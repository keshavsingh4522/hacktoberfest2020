#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, multiset<string>> marks_map;//here we use multi set becoz if in our there are two student with same name then multi map save it
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int marks;
        string name;
        cin >> name >> marks;
        marks_map[marks].insert(name);
    }
auto cur_it = --marks_map.end();
while(true){
    auto students = (*cur_it).second;
    int marks =(*cur_it).first;
    for(auto student: students){
          cout<<student<<" "<<marks<<endl;

    }
    if(cur_it==marks_map.begin()) break;
    cur_it--;
}

    return 0;
}