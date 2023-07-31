class Solution {
public:
    int maxProfit(vector<int>& prices) {

    //  O(1) SPACE
    
    //  int lsf = prices[0];
    //  int mp = 0;
    //  int cp = 0;
    //     for(int i = 1; i < prices.size(); i++){
    //         cp = prices[i] - lsf;
    //         if(prices[i] < lsf){
    //             lsf = prices[i];
    //         }
    //         if(mp < cp){
    //             mp = cp;
    //         }
    //     }
    //     return mp;

    int ans = 0;
    int msf = prices[0];

    for(int i = 0; i < prices.size(); i++){
        ans = max(ans, prices[i] - msf);
        if(prices[i] < msf) msf = prices[i];
    }
    return ans;
    }
};