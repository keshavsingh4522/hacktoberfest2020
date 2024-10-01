#include <bits/stdc++.h>
using namespace std;

int evenNum(int n)
{
    int evCount = 0;
    while (n > 1)
    {
        n = n / 2;
        evCount++;
    }
    return evCount;
}

int oddNum(int n)
{

    int count = 0;
    while (n > 1)
    {
        n = n - 2;
        count++;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a;
        cin >> n >> a;

        if (n == 1 || n == 2 || n == 3)
        {
            cout << a << endl;
        }

        else if (n % 2 == 0)
        {

            int sua = evenNum(n);

            if (sua % 2 != 0)
            {
                int ans = (sua - 1) * a;
                cout << ans << endl;
            }
            else if (sua % 2 == 0)
            {
                int ans1 = sua * a;
                cout << ans1 << endl;
            }
        }

        else
        {
            int sq = oddNum(n);
            if (sq % 2 != 0)
            {
                cout << (sq - 1) * a << endl;
            }
            else if (sq % 2 == 0)
            {
                cout << sq * a << endl;
            }
        }
    }
    return 0;
}
