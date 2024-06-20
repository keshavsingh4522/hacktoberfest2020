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
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        for(int i=0;i<=rowIndex;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(nCr(i,j));
            }
            result.push_back(temp);
        }
        return result[rowIndex];
    }
};
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
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        for(int j=0;j<=rowIndex;j++){
            temp.push_back(nCr(rowIndex,j));
        }
        return temp;
    }
};