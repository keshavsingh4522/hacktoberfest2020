#include<stdio.h>


int  arr[255];

int main() {

    int n,k;

  scanf("%d %d", &n, &k);

  for (int i = 1; i <= n * 2 + 1; ++i) 
  {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i <= n; ++i) 
  {
    if (k == 0) 
    {
        continue;
    }

    if (arr[i * 2] - 1 > arr[i * 2 - 1] && arr[i * 2] - 1 > arr[i * 2 + 1]) 
            {
              --k;
              --arr[i * 2];
            }
  }

  for (int i = 1; i <= n * 2; ++i) 
  {
      printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n * 2 + 1]);


  return 0;
}

/*
INPUT:
    3 2
    0 5 3 5 1 5 2
OUTPUT:
      
      0 4 3 4 1 5 2
        
INPUT:
    1 1
    0 2 0
OUTPUT: 
     0 1 0 
        
*/
