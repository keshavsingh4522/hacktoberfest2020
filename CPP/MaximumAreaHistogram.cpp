//Implementing largest area histogram using stack based solution in O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()!=0){
        stack <int> s;
        int curr_area,x,i=0;
        vector<int> areas;
        int n = heights.size();
        while(i<n){
           if(s.empty() || heights[s.top()]<=heights[i])
           {
               s.push(i++);
           }else{
               if(heights[s.top()]<heights[i]){
                   s.push(i);
               }else{
                   x = s.top();
                   s.pop();
                   if(s.empty())
                       curr_area = heights[x] * i;
                   else
                       curr_area = heights[x] *(i-s.top()-1);
                   areas.push_back(curr_area);
               }
           }
            
        }
        while(!s.empty()){
            x = s.top();
            s.pop();
            if(s.empty())
                curr_area = heights[x] * (i);
            else
                curr_area = heights[x] *(i-s.top()-1);
            areas.push_back(curr_area);
        }
        for(i=0;i<n;i++){
            cout<<areas[i]<<" ";
        }
        return *max_element(areas.begin(), areas.end());
    }
        
    
        else{
            return 0;
        }
    }
};
