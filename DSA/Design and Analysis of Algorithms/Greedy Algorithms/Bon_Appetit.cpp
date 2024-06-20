#include<bits/stdc++.h> 
using namespace std;
struct Slot{
    int curr_start,curr_end,id = -1;
};
bool comparator(Slot s1,Slot s2)
{
    if(s1.curr_end == s2.curr_end)
    return s1.curr_start < s2.curr_start;
    return s1.curr_end < s2.curr_end;
}
void solve()
{
    int t,n,k,ans=0;
    cin>>t;
    while(t--)
    {
        ans = 0;
        cin>>n>>k;
        vector<Slot> customers(n);
        map<int,Slot> slots;
        for(int i = 0;i<n;i++)
        cin>>customers[i].curr_start>>customers[i].curr_end>>customers[i].id;
        sort(customers.begin(),customers.end(),comparator);

        for(Slot cust : customers)
        {
            if(slots.find(cust.id)== slots.end())
            {
              slots[cust.id] = cust;
                ans++;
            }
            else if(slots.find(cust.id) != slots.end())
            {
                if(cust.curr_start >= slots[cust.id].curr_end)
                {
                slots[cust.id].curr_start = cust.curr_start;
                slots[cust.id].curr_end = cust.curr_end;
                ans++;
                }
            }
        }
        cout<<ans<<"\n";

        

    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
