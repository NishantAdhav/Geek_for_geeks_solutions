/*Given a number N, the task is to find the largest prime factor of that number.
 Example 1:

Input:
N = 5
Output:
5
Explanation:
5 has 1 prime factor i.e 5 only.
Example 2:

Input:
N = 24
Output:
3
Explanation:
24 has 2 prime factors 2 and 3 in which 3 is greater.
Your Task:
You don't need to read input or print anything. Your task is to complete the function largestPrimeFactor() which takes an integer N as input parameters and returns an integer, largest prime factor of N.

Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(1)

Constraints:
2 <= N <= 109
*/
//{ Driver Code Starts
#include<iostream> 
using namespace std;

// } Driver Code Ends

class Solution{
public: 
    long long int largestPrimeFactor(int N)
    {
        long long int ans=0;
        long long int i;
        for(i=2;i*i<=N;i++)  // Adjusted condition here
        {
            while(N%i==0)
            {
                if(i>ans)
                {
                    ans=i;
                }
                N=N/i;
            }
        }
        if(N>1)
        {
            if(N>ans)
            {
                ans=N;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends

