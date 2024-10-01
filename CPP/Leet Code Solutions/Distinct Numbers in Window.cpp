vector<int> Solution::dNums(vector<int> &A, int k) {

    int n = A.size();
    
    vector<int> res;
    unordered_map<int,int> m;
    int distinct_count = 0;
    for(int i=0;i<k;i++)
    {
       if(m[A[i]]==0)
       distinct_count++;

       m[A[i]]++;

       
    }
     res.push_back(distinct_count);

    for(int i=k;i<n;i++)
    {
        if(m[A[i-k]]==1)
        distinct_count--;

        m[A[i-k]]--;

        if(m[A[i]]==0)
        distinct_count++;
        res.push_back(distinct_count);
        m[A[i]]++;
    }
    return res;
}