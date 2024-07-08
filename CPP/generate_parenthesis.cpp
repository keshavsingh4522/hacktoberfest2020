#include <bits/stdc++.h>
using namespace std;

void addingpar(vector<string> &v, string str, int n, int m) {
    if (n == 0 && m == 0) {
        v.push_back(str);
        return;
    }
    if (m > 0) { addingpar(v, str + ")", n, m - 1); }
    if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    addingpar(res, "", n, 0);
    return res;
}

int main()
{
    int n;
    cin>>n;

    vector<string> v = generateParenthesis(n);

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
}
