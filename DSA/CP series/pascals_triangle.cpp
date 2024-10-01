class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==0)
            return vector<vector<int>> ();
        vector<vector<int>>vt;
        vt.push_back({1});
        vector<int>a;
        
        for(int i=1;i<numRows;i++)
        {
        vector<int>a(i+1);
        a[0]=a[i]=1;
        for(int j=1;j<i;j++)
            a[j]=vt[i-1][j]+vt[i-1][j-1];
         vt.push_back(a);
        }
        return vt;   
    }
};
