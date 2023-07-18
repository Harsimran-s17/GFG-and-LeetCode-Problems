class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        int rowSt = 0;
        int colSt = 0;
        vector<int> vec;

        while(rowSt <= row && colSt <= col){
            for(int i = colSt; i <= col; i++){
                vec.push_back(matrix[rowSt][i]);
            }
            rowSt++;
            
            for(int i = rowSt; i <=row; i++){
                vec.push_back(matrix[i][col]);
            }
            col--;
            
            if(rowSt<= row && colSt <= col){
                for(int i = col; i >= colSt; i--){
                    vec.push_back(matrix[row][i]);
                }
                row--;
                
                for(int i = row; i >= rowSt; i--)
                    vec.push_back(matrix[i][colSt]);
                
                colSt++;
            }
            
        }
        return vec;
    }
};