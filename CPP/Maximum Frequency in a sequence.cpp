/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<             Program of Maximum Frequency in a sequence          >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

Given a list of integers, find out the number that has the highest frequency. If there are one or more such numbers, output the smaller one.

Input:

First line of input will contain an integer T = number of test cases. 
Each test case will contain two lines:
First line will contain an integer N = number of elements in the sequence. 
Next line will contain N space separated integers of sequence A.

Output:

For each test case, print on a single line, the number with highest

Constraints

1 <= T <= 100
1 <= N <= 10^5
1 <= A[i] <= 1000

Sample Input

3
7
2 4 5 2 3 2 4
6
1 2 1 1 2 1
10
1 1 1 1 1 1 1 1 1 1

Sample Output

2
1
1

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<       Solution of Program    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#in>>clude<iostream>>>>
using namespace std;
int main()
{
  int x,i;
  cin>>x;
  for(i=0;i<x;i++){
    int n,i,j,max=0,m=0;cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
      cin>>arr[i];
    }
    for(i=0;i<n;i++){
      int count=0;
      for(j=i+1;j<n;j++){
        if(arr[i]==arr[j]){
          count++;
        }
        if(count>=max){
          max=count;
          m=arr[i];
        }
      }
    }
    cout<<m<<endl;
  }
}


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                           Contributed By Sonu                                  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
