class Solution {
public:
    void reverseArr(vector<int> &arr, int s, int e){
        while(s<e) {swap(arr[e--], arr[s++]);}
    }
    
    void nextPermutation(vector<int>& arr) {
//         int n = nums.size();
//         int i = n-2;
//         int j = n-1;

//         for(i; i >=0; i--){
//             if(nums[i] < nums[i+1]) break;
//         }

//         if(i>= 0){
//         for(j; j >i; j--){
//             if(nums[j] > nums[i]) break;
//         }
//         swap(nums[i], nums[j]);
//         }


//         reverse(nums.begin() + i+1 , nums.end());
         int i;
        int n = arr.size();
        for(i = n-1; i > 0; i--){
            if(arr[i]>arr[i-1]) break;
        }
        
        if(i!=0){
            int j = n-1;
            while(arr[i-1]>=arr[j] && j!=i-1)j--;
            swap(arr[i-1],arr[j]);
            
        }
            reverseArr(arr, i, n-1);
    }
};