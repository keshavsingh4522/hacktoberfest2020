class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int max=0;int min=0;
        for(int i=0;i<n-1;i++)
        {
            if(height[i]<min)
                continue;
            for(int j=n-1;j>i;j--)
            {   if(height[j]<min)
                continue;
                min =height[i]<height[j]?height[i]:height[j];
                int area= min*(j-i);
                max=area>max?area:max;
            }
        }
        return max;
    }
};
//order of n^2
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> max_area;
        vector<int>::iterator ptr1,ptr2;
        for(ptr1=height.begin();ptr1=height.end();ptr1++){
            for(ptr2=height.begin();ptr2=height.end();ptr2++){
                int dist=std::distance(pt1,ptr2);
                if(*ptr1>*ptr2){
                    max_area.push_back(dist*(*ptr2));
                }
                else{
                    max_area.push_back(dist*(*ptr1));
                }
            }
        }
        int maxm=*max_element(max_area.begin(),max_area.end());
        return maxm;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> max_area;
        vector<int>::iterator ptr1;
        vector<int>::iterator ptr2;
        int max=*max_element(max_area.begin(),max_area.end());
        while(*pt2!=max || ptr!=height.end()){
            pt2++;
        }
        for(ptr1=height.begin();ptr1!=height.end();ptr1++){
            int dist=std::distance(ptr1,ptr2);
            if(*ptr1>*ptr2){
                max_area.push_back(dist*(*ptr2));
            }
            else{
                max_area.push_back(dist*(*ptr1));
            }
        }
        int maxm=*max_element(max_area.begin(),max_area.end());
        return maxm; 
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int> max_area;
        int max=*max_element(height.begin(),height.end());
        int i=0;
        while(height[i]!=max || i<height.size()){
            i++;
        }
        for(int j=0;j<height.size();j++){
            int dist=abs(i-j);
            max_area.push_back(dist*height[j]);
        }
        return *max_element(max_area.begin(),max_area.end());
    }
};