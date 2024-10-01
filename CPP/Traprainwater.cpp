#include <bits/stdc++.h>
#include <vector>
using namespace std;

int trapwater(vector<int> &height)
{
    int n=height.size();
    if(n<=2)
    {
        return 0;
    }
    int maxleft=height[0];
    int maxright=height[n-1];
    int left=1;
    int right=n-2;
    int trapwater=0;

    while(left<=right)
    {
        if(maxleft<=maxright)
        {
            if(height[left]>=maxleft)
            {
                maxleft=height[left];
            }
            else
            {
                trapwater+=maxleft-height[left];
            }
            left++;
        }
        else
        {
            if(height[right]>=maxright)
            {
                maxright=height[right];
            }
            else
            {
                trapwater+=maxright-height[right];
            }
            right--;
        }
    }
    return trapwater;
}

int main()
{
    vector<int> height;
    height.push_back(4);
    height.push_back(2);
    height.push_back(0);
    height.push_back(3);
    height.push_back(2);
    height.push_back(5);
    cout<<trapwater(height);
}




