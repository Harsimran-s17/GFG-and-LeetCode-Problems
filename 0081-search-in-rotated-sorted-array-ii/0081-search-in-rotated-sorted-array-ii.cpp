class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid]){
                if(nums[mid] > target && nums[l] <= target) r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(nums[mid] < target && nums[r] >= target) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;


        // int n = arr.size();
        // for(int i = 0; i < (2*n); i++){
        //     if(arr[i%n] == target) return true;
        // }
        // return false;
    }
};