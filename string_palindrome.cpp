/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
Your Task:
You don't need to read input or print anything. Complete the function isPalindrome()which accepts string S and returns an integer value 1 or 0.

Expected Time Complexity: O(Length of S)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Length of S<= 2*105

*/
#include <iostream>
using namespace std;

class Solution {
public:
    int isPalindrome(string S) {
        int left = 0, right = S.length() - 1;

        while (left < right) {
            if (S[left] != S[right]) {
                return 0;  // Not a palindrome
            }
            left++;
            right--;
        }

        return 1;  // Palindrome
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.isPalindrome(s) << "\n";
    }

    return 0;
}

