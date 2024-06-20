class Solution
{
public:
    int climbStairs(int n)
    {
        //fibonacci
        if (n < 3)
            return n;
        int x = 1;
        int y = 2;
        int ans;
        for (int i = 3; i <= n; i++)
        {
            ans = x + y;
            x = y;
            y = ans;
        }
        return ans;
    }
};