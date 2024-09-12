        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here - rahul
            int i=0,j=0,k=(n-1);
            while(i<=k and j<m)
                {
                    if(arr1[i]<arr2[j])
                    {
                        i++;
                     
                    }
                    else
                    {
                        swap(arr2[j],arr1[k]);
                        j++;
                        k--;
                        
                    }
                }
            
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
