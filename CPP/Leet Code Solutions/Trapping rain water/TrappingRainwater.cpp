class Solution {
public:
    int trap(vector<int>& height) {
      int low=0,  high=0,n=height.size();
    int left[n];
        int right[n];
        int water=0;
       
        for(int i=0;i<n;i++){
            if (height[i]>low){
                left[i]=height[i];
                low=height[i];
            }
            else{
                left[i]=low;
           }
             cout<<left[i]<<" ";
        }
        cout<<endl;
        for(int i=n-1;i>=0;i--){
          if(height[i]>high){
                right[i]=height[i];
               high=height[i];
            }
            else{ 
                 right[i]=high; 
        }
        cout<<right[i]<<" ";}
        for(int i=1;i<n-1;i++){
           water=water+(min(left[i],right[i])-height[i]); 
        }
        return water;}
        
   

};