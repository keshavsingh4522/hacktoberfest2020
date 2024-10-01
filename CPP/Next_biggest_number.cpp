#include<iostream>
#include<algorithm>
using namespace std;

/*Short cut method 
int main(){
int numbers[]={6,7,3};
next_permutation(numbers,numbers+3);
cout<<numbers[0]<<numbers[1]<<numbers[2];
system("pause");    
return 0;
}
*/

/*Other wise */

int main(){
    
int a[] ={1,2,3,4,5,6,7,8,4,9,8,7,6,5,4,3,2,1};
int len = sizeof(a)/sizeof(int);
int i,j;


for(i=len-1;i>=0;i--){
if(a[i-1]<a[i])
break;
}
int current_min=a[i-1];
int index=-1;    
for(j=i;j<len;j++){
if(a[j]>current_min)
{current_min=min(current_min,a[j]);
 index = j;}
}

int temp = a[i-1];
a[i-1] = a[index];
a[index] = temp;

sort(a+i,a+len);
    
for(i=0;i<len;i++)
cout<<a[i];

system("pause");
return 0;
}
