class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int res=A.size()+1;
        deque <int> d;
        for(int i=0;i<A.size();i++){
            if(i>0)
                A[i]+=A[i-1];
            if(A[i]>=K)
                res=min(res,i+1);
            while(d.size()>0 && A[i]-A[d.front()]>=K)
                res = min(res, i-d.front()), d.pop_front();
            while(d.size()>0 && A[i]<=A[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res<=A.size()?res:-1;
        
    }
};
