class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int maxi = 0;
        int area = 0;
        int j = n - 1;
        for (int i = 0; i < j;) {
            int l = abs(j - i);
            int b = min (v[i], v[j]);
            area = l * b;
            maxi = max(maxi, area);
            if (v[j] < v[i])
                j--;
            else
                i++;
        }
        return maxi;
    }
};