
class Solution {
public:
    int nCr(int n, int r)
    {
        long long p = 1, k = 1;
        if (n - r < r)
            r = n - r;
        if (r != 0) {
            while (r) {
                p *= n;
                k *= r;
                long long m = __gcd(p, k);
                p /= m;
                k /= m;
                n--;
                r--;
            }
        }
        else
            p = 1;
        return p;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(nCr(i,j));
            }
            result.push_back(temp);
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }
};
class Solution {
public:
    unsigned long long int fact(int n)
    {
        unsigned long long int res = 1;
        for (int i = 2; i <= n; i++)
            res = res * i;
        return res;
    }
    unsigned long long int nCr(int n, int r)
    {
        return fact(n) / (fact(r) * fact(n - r));
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(nCr(i,j));
            }
            result.push_back(temp);
        }
        return result;
    }
};

