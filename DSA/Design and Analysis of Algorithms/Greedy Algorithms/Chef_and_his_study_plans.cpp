// Not Solved (Under Review)


#include<bits/stdc++.h> 
using namespace std;
struct Time{
    int startTime,endTime;
};
bool comparator(Time t1,Time t2)
{
    if(t1.endTime == t2.endTime)
    return t1.startTime < t2.startTime;
    return t1.endTime < t2.endTime;
}
void solve()
{
    int n,q,ans,start,end,t1,t2;
    cin>>n>>q;
    vector<Time>sub(n);
    for(int i = 0;i<n;i++)
        cin>>sub[i].startTime>>sub[i].endTime;
    sort(sub.begin(),sub.end(),comparator);
    while(q--)
    {
        ans = 0;
            cin>>start>>end;
            t1 = start,t2 = end;
            for(Time t : sub)
            {
                if(t2 >= t.startTime and t.startTime >= start and t.endTime <= end )
                ans ++ , t2 = t.endTime;

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
