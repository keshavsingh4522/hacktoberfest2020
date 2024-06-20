#include<stdio.h>
#include<conio.h>
using namespace std;
int main()
{
    int n,m,x;
    int arr;
    cin >> n >> m >> x;
    cin >> arr;

    bool flag = false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]==x)
            {
                cout << i << " " << j << "\n";
                flag = true;
            }
        }
    }

    if(flag)
    {
        cout << "Element is Found \n";
    }
    else
    {
        cout << "Element is Not Found \n";
    }
    getch();
    return 0;
}
