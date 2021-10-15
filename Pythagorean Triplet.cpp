/*
Given an array arr of N integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2, otherwise false.

Example 1:

Input:
N = 5
Arr[] = {3, 2, 4, 6, 5}
Output: Yes
Explanation: a=3, b=4, and c=5 forms a
pythagorean triplet.
Example 2:

Input:
N = 3
Arr[] = {3, 8, 5}
Output: No
Explanation: No such triplet possible.
Your Task:
Complete the function checkTriplet() which takes an array arr, single integer n, as input parameters and returns boolean denoting answer to the problem. You don't to print answer or take inputs. 
Note: The driver will print "Yes" or "No" instead of boolean.

Expected Time Complexity: O(max(Arr[i])2)
Expected Auxiliary Space: O(max(Arr[i]))

Constraints:
1 <= N <= 107
1 <= Arr[i] <= 1000
*/
#include <iostream>
 
using namespace std;
 
// Returns true if there is Pythagorean triplet in ar[0..n-1]
bool isTriplet(int ar[], int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                // Calculate square of array elements
                int x = ar[i] * ar[i], y = ar[j] * ar[j], z = ar[k] * ar[k];
 
                if (x == y + z || y == x + z || z == x + y)
                    return true;
            }
        }
    }
 
    // If we reach here, no triplet found
    return false;
}
 
/* Driver program to test above function */
int main()
{
    int ar[] = { 3, 1, 4, 6, 5 };
    int ar_size = sizeof(ar) / sizeof(ar[0]);
    isTriplet(ar, ar_size) ? cout << "Yes" : cout << "No";
    return 0;
}
