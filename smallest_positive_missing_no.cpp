//{ Driver Code Starts

/*You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
*/


#include<iostream>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {
       // Step 1: Mark the presence of positive numbers using indices
        for (int i = 0; i < n; i++)
        {
            // Ignore elements outside the range 1 to n
            while (arr[i] > 0 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }

        // Step 2: Find the first missing positive number
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
                return i + 1;
        }

        // If all positive numbers are present, return the next positive number
        return n + 1;
        
    }

        
        
 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends