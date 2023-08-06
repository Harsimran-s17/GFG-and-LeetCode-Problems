//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void solve(string S, int index, vector<string> &vec){
        if(index==S.length()){
            vec.push_back(S);
            return;
        }
        
        for(int i = index; i < S.length(); i++){
            swap(S[index],S[i]);
            solve(S,index+1,vec);
            swap(S[index],S[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> ans;
        solve(S, 0, ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends