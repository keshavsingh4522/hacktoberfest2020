int kadanes(int A[],int n)
    {
        int sum=0;
        int max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum>max)
            {
              max=sum;
            }
            if(sum<0)
            {
              sum=0;
            }
        }
        return max;
    }
    
    int maxSubarraySum(int arr[], int n){
        int sum=0;
        int max=kadanes(arr,n);
        if(max==0)
        {
            for(int i=0;i<n;i++)
            {
                if(max<arr[i])
                {
                    max=arr[i];
                }
            }
        }
        return max;
    }
};
