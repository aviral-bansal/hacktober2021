/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ |S| ≤ 103
*/

// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

// A utility function to print
// a substring str[low..high]
// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(char* str)
{
    // The result (length of LPS)
    int maxLength = 1;

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every
    // character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i) {
        // Find the longest even length palindrome
        // with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }

          // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }

        // Find the longest odd length
        // palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len
               && str[low] == str[high]) {
            --low;
            ++high;
        }

        // Move back to the last possible valid palindrom substring
          // as that will anyway be the longest from above loop
        ++low; --high;
          if (str[low] == str[high] && high - low + 1 > maxLength) {
            start = low;
              maxLength = high - low + 1;
        }
    }

    cout << "Longest palindrome substring is: ";
    int ans=maxlength;  
    while(ans--)
      cout<<str[start++];

      return maxLength;
}

// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str)
         << endl;
    return 0;
}

// This is code is contributed by rathbhupendra
