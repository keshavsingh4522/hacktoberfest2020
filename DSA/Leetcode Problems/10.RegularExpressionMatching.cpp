// f[i][j] = f[i - 1][j - 1]  case s[i - 1] == p[j - 1] or p[j - 1] == '.'
// f[i][j] = f[i][j - 2] or f[i - 1][j] where s[i - 1] == p[j - 2] or p[j - 2] == '.'    case p[j - 1] == '*'
//
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
        
        
        for (auto i = 0; i <= m; ++i)
        {
            for (auto j = 0; j <=n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    table[i][j] = true;
                    continue;
                }
                
                if (j == 0)
                {
                    table[i][j] = false;
                    continue;
                }
                
                if (p[j - 1] != '*')
                {
                    if (i - 1 >= 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1]))
                    {
                        table[i][j] = table[i - 1][j - 1];
                    }
                }
                else
                {
                    if (j - 2 >= 0)
                    {
                        table[i][j] = table[i][j - 2];
                        if (i - 1 >= 0 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                        {
                            table[i][j] = table[i][j] || table[i - 1][j];
                        }
                    }
                }
            }
        }
        
        return table[m][n];
    }
};