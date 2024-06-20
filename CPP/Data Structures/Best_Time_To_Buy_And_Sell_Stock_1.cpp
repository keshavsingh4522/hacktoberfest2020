class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int currentMin = INT_MAX;
        int result = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            result = max(result, prices[i] - currentMin);
            currentMin = min(currentMin, prices[i]);
        }

        return result;
    }
};