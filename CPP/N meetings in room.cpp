//@soumyaagr427

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
  
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
  
    int maxMeetings(int start[], int end[], int n)
    {
        int curr=1;
        
        vector<pair<int,int>>ans;
        
        //pushing the pairs into vectors
      
        for(int i=0;i<n;i++)
            ans.push_back(make_pair(end[i],start[i]));
            
        sort(ans.begin(),ans.end());
            
        int time_limit=ans[0].first;
        
        for(int i=1;i<n;i++)
        {
            if(time_limit<ans[i].second)
            {
                curr++;
                time_limit=ans[i].first;
            }
        }
        
        return curr;
    }
    
    
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
