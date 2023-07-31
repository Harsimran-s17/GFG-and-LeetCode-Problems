class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int msf = prices[0];
        int cp = 0;

        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < msf){
                msf = prices[i];
                ans += cp;
                cp = 0;
            }
            if(cp > (prices[i]-msf)){
                ans += cp;
                cp = 0;
                msf = prices[i];
            }
            else cp = prices[i]-msf;
        }
        ans+= cp;
        return ans;
    }
};