/*Given a string S. The task is to find all permutations (need not be different) of a given string.

Example 1:

Input:
S = AAA
Output: AAA AAA AAA AAA AAA AAA
Explanation: There are total 6 permutations, as given in the output.
Example 2:

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA
Explanation: There are total 24 permutations, as given in the output.
Your Task:
This is a function problem. You only need to complete the function permutation that takes S as parameter and returns the list of permutations in lexicographically increasing order. The newline is automatically added by driver code.

Constraints:
1 ≤ size of string ≤ 5

Expected Time Complexity: O(N * N!), N = length of string.
Expected Auxiliary Space: O(1)
*/
//{ Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        vector<string>ans;
        string cur="";
        vector<bool> vis(S.size(),0);  //visit array is initialize to 0.
        
        function<void()>helper=[&]()
        {
            if(cur.size()==S.size())
            {
                ans.push_back(cur);
                return;
            }
            for(int i=0;i<S.size();i++)
            {
                if(!vis[i])
                {
                    cur.push_back(S[i]);
                    vis[i]=1;
                    helper();
                    vis[i]=0;
                    cur.pop_back();
                }
            }
        };
        
        helper();
        
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

