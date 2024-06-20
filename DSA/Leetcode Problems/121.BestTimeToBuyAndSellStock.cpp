//order of N
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=10000;
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            if(min_price>prices[i]){
                min_price=prices[i];
            }
            if(prices[i]-min_price>max_profit){
                max_profit=prices[i]-min_price;
            }
        }
        return max_profit;
    }
};
/order of N^2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                int profit=prices[j]-prices[i];
                if(max<profit){
                    max=profit;
                }
            }
        }
        return max;
    }
};
/* Use Less
class Solution {
public:
    int MyMaxProfit(vector<int>& prices) {
        vector<int> temp=prices;
        sort(temp.begin(),temp.end(),greater<int>());
        if(temp==prices){
            return 0;
        }
        auto it1=min_element(prices.begin(),prices.end());
        if(it1==prices.end()-1){
            prices.pop_back();
            return MyMaxProfit(prices);
        }
        auto it2=max_element(it1,prices.end());
        return *it2-*it1;
    }
    int maxProfit(vector<int>& prices) {
        return MyMaxProfit(prices);
    }
};
*/