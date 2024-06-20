#include<bits/stdc++.h>
using namespace std;
struct Objects{
    float value,weight,ratio;
};
bool comparator(Objects o1,Objects o2)
{
return o1.weight < o2.weight;
}
int main()
{
    int capacity,n;
    float profit = 0,temp;
    cin>>capacity;
    cin>>n;
    vector<Objects>obj(n);
    for(int i = 0;i<n;i++)
    {
        cin>>obj[i].value>>obj[i].weight;
    obj[i].ratio = obj[i].value/obj[i].weight;
    }
    sort(obj.begin(),obj.end(),comparator);

    for(Objects objs : obj)
    {
    
        if(objs.weight <= capacity)
        {
            profit += objs.value;
            capacity = capacity - objs.weight;
        }
        else if(objs.weight > capacity)
        {
            profit += (capacity)*(objs.ratio);
            capacity = 0;
        }
        else if(capacity == 0)
        break;
    }
    cout<<profit;


}