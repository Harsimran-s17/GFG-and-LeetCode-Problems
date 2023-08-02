class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        int ele = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] > ele){
                ans = max(ans, nums[i] - ele);
            }
            else{
                ele = nums[i];
            }
        }
        return ans;
    }
};