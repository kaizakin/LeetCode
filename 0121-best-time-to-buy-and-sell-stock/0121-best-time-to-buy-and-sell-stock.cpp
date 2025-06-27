class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int sell=0;
        for(int i=1;i<prices.size();++i){
          buy=min(buy,prices[i]);
          sell=max(prices[i]-buy,sell);
        }  
        return sell; 
    }
};