// Example program
/*
Water Flow Program.
Given an integer array of size n x m, Water will always start to flow from the middle point of the 0th row.
0 represent water can flow in through that cell.
1 represent there is a block to flow.
water can flow vertically downwards and it will split to flow horizontally left  and right if it encounters a block vertially.

print all the points(indexes) where it can reach in the (n-1) row.

This question was asked in a Online Test in a company.

solution given: recursive.
*/


#include <iostream>
// #include <string>
using namespace std;
void checkPath(int a[][30], int n, int m, int i, int j)
{
    if(i==n-1)
    {
        cout<<j<<endl;
        return;
    }
    if(i+1<n)
    {
        if(a[i+1][j] ==0)
        {
            checkPath(a,n,m,i+1,j);
            return;
        }
        else
        {
            if(j-1>=0 && a[i][j-1]==0) 
            {
                checkPath(a,n,m,i,j-1);return;
            }
            if(j+1<m && a[i][j+1]==0)
            {
                checkPath(a,n,m,i,j+1);return;
            }
        }


    }
}
int main()
{

 int n=5,m=7;
 int a[5][30]={
     {0,0,0,0,0,0,0},
     {0,0,1,1,1,0,1},
     {1,01,1,0,0,0,0},
     {0,0,0,1,1,0,1},
     {0,0,0,0,0,0,0}
     };

 //  always start at a[0][m/2]
//  checkPath(array, no_rows,no_cols, i,j)
 checkPath(a,n,m,0,m/2);

}
