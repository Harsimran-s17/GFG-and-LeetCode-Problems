class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size(), col = mat[0].size();
	    
	    int low = 0;
        int high = row - 1;
        int r ;
        
        while(low <= high){
            r = (low+high)>>1;
            if(target >= mat[r][0] && target <= mat[r][col-1]) break;
            else if (target < mat[r][0]) high = r -1;
            else low = r + 1;
        }
        
        low = 0;
        high = col - 1;
        int c;
        while(low <= high){
            c = (low+high)>>1;
            if(target == mat[r][c]) return true;
            else if(target < mat[r][c]) high = c - 1;
            else low = c + 1;
        }
        return false;
    }
};