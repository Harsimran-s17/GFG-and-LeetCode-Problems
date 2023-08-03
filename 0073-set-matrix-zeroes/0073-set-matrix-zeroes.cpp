class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vec;
    int n = matrix.size();
    int m = matrix[0].size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matrix[i][j]==0) vec.push_back({i,j});
		}
	}
	
	for(auto i : vec){
		for(int j = 0; j < m; j++){
			matrix[i.first][j] = 0;
		}
		for(int j = 0; j < n; j++){
			matrix[j][i.second] = 0;
		}
	}
    }
};