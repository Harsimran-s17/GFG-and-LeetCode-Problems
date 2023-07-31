//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int r = matrix.size();
        int c = matrix[0].size();
        
         vector<vector<int>> vec;
        
        for(int i = 0; i < r; i++){
            vector<int> mat;
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0) mat.push_back(1);
                else mat.push_back(0);
            }
            vec.push_back(mat);
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int count = 0;
                if(vec[i][j] == 1){
                    if(i-1>=0 && !vec[i-1][j]) count += matrix[i-1][j];
                    
                    if(i+1<r && !vec[i+1][j]) count += matrix[i+1][j];
                    
                    if(j-1>=0 && !vec[i][j-1]) count += matrix[i][j-1];
                    
                    if(j+1<c && !vec[i][j+1]) count += matrix[i][j+1];
                    
                    matrix[i][j] = count;
                }
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int count = 0;
                if(vec[i][j] == 1){
                    if(i-1>=0 && !vec[i-1][j] ) matrix[i-1][j] = 0;
                    
                    if(i+1<r && !vec[i+1][j]) matrix[i+1][j] = 0;
                    
                    if(j-1>=0 && !vec[i][j-1]) matrix[i][j-1] = 0;
                    
                    if(j+1<c && !vec[i][j+1]) matrix[i][j+1] = 0;
                    
                    vec[i][j] = 0;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends