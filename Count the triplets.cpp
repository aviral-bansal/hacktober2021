/*
Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
 
Example 1:

Input:
N = 4
arr[] = {1, 5, 3, 2}
Output: 2
Explanation: There are 2 triplets: 
1 + 2 = 3 and 3 +2 = 5 
â€‹Example 2:

Input: 
N = 3
arr[] = {2, 3, 4}
Output: 0
Explanation: No such triplet exits
Your Task:  
You don't need to read input or print anything. Your task is to complete the function countTriplet() which takes the array arr[] and N as inputs and returns the triplet count

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 103
1 ≤ arr[i] ≤ 105
*/
// CPP program to find three numbers
// such that sum of two makes the
// third element in array
#include <bits/stdc++.h>
using namespace std;

// Utility function for finding
// triplet in array
void findTriplet(int arr[], int n)
{
	// sort the array
	sort(arr, arr + n);

	// for every element in arr
	// check if a pair exist(in array) whose
	// sum is equal to arr element
	for (int i = n - 1; i >= 0; i--) {
		int j = 0;
		int k = i - 1;

		// Iterate forward and backward to find
		// the other two elements
		while (j < k) {

			// If the two elements sum is
			// equal to the third element
			if (arr[i] == arr[j] + arr[k]) {

				// pair found
				cout << "numbers are " << arr[i] << " "
					<< arr[j] << " " << arr[k] << endl;
				return;
			}

			// If the element is greater than
			// sum of both the elements, then try
			// adding a smaller number to reach the
			// equality
			else if (arr[i] > arr[j] + arr[k])
				j += 1;

			// If the element is smaller, then
			// try with a smaller number
			// to reach equality, so decrease K
			else
				k -= 1;
		}
	}

	// No such triplet is found in array
	cout << "No such triplet exists";
}

// driver program
int main()
{
	int arr[] = { 5, 32, 1, 7, 10, 50, 19, 21, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findTriplet(arr, n);
	return 0;
}

