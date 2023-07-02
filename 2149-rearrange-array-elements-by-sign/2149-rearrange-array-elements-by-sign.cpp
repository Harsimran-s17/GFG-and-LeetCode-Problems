class Solution {
public:

    void rotate(vector<int> & a, int s, int e){
        int temp = a[e];
        for(int i = e; i > s; i--) a[i] = a[i-1];
        a[s] = temp;
    }
    vector<int> rearrangeArray(vector<int>& nums) {
        // int n = nums.size();
        // int outOfIndex;
        // for(int i = 0; i < n; i++){
        //     if((!(i%2) && nums[i] < 0) || ((i%2) && nums[i]>=0)){
        //         outOfIndex = i;
        //         // cout<<outOfIndex<<endl;
        //         int j;
        //         for(j = i+1; j< n; j++){
        //             if((nums[j]<0 && nums[j-1]>0) || (nums[j]>0 && nums[j-1]<0)) break;
        //         }
        //         if(j==n) j--;
        //         rotate(nums,outOfIndex, j);
        //         i += 1;
        //     }
        // }
        // return nums;

        vector<int> pos;
        vector<int> neg;

        for(int i = 0; i < nums.size();i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int j = 0, k = 0;
        int i;
        for(i = 0; i < nums.size(); ){
            if(j == neg.size() || k == pos.size()) break;
            if(i%2) nums[i++] = neg[j++];
            else nums[i++] = pos[k++];
        }

        while(j<neg.size()){
            nums[i++] = neg[j++];
        }

        while(k<pos.size()){
            nums[i++] = pos[k++];
        }

        return nums;
    }
};