/*
Given a number, in the form of an array Num[] of size N containing digits from 1 to 9(inclusive). The task is to find the next smallest palindrome strictly larger than the given number.

Example 1:

Input:
N = 11
Num[] = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2}
Output: 9 4 1 8 8 0 8 8 1 4 9
Explanation: Next smallest palindrome is
9 4 1 8 8 0 8 8 1 4 9
Example 2:

Input:
N = 5
Num[] = {2, 3, 5, 4, 5}
Output: 2 3 6 3 2
Explanation: Next smallest palindrome is
2 3 6 3 2
Your Task:
Complete the function generateNextPalindrome() which takes an array num, and a single integer n, as input parameters and returns an array of integers denoting the answer. You don't to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 105
1 <= Num[i] <= 9
*/
//{ Driver Code Starts
#include <iostream>
#include<vector>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
	vector<int> generateNextPalindrome(int a[], int n) {
	   vector<int> ans;
	  int carry, solved=0;
	    for( int i=n/2; i<n ;i++){
	        if(a[i] < a[n-i-1]){
	            a[i] = a[n-i-1];
	            for(int j=i+1; j<n ;j++){
	                a[j] = a[n-j-1];
	            }
	            solved=1;
	            break;
	        }
	        else if(a[i] > a[n-i-1])  break;
	    }
	    
	    if(solved==1){
    	    for(int i=0; i<n; i++)    ans.push_back(a[i]);
    	    return ans;
	    }

	    // decremental case
	    else{
	    carry=1;
	    for(int i=(n-1)/2; i>=0 ;i--)
	    {
	        if(a[i] + carry ==10)
	        {
	            a[i] =0;
	            carry=1;
	        }
	        else
	        {
	            a[i]++; 
	            carry=0;
	            break;
	        }
	    }
	    //
	    if(carry==1)
	    ans.push_back(1);
	    
	    for(int i=0; i<n; i++)
	    ans.push_back(a[i]);
	    
	    if(carry==1) n++;
	    
	    for(int i=(n+1)/2 ;i<n; i++)
	    ans[i] = ans[n-i-1];
	    
	    return ans;
	        
	    }
	   
	}

};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends