class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<int, int> m;
        int l = tasks.size();
        if (n == 0)
            return l;
        for (auto x : tasks)
            m[x]++;
        int max_freq = 0;
        for (auto x : m)
            if (x.second > max_freq)
                max_freq = x.second;

        int ans = (max_freq - 1) * (n + 1);
        for (auto x : m)
            if (x.second == max_freq)
                ans++;

        return max(ans, l);
    }
};