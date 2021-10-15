/*
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them. Any correct solution will result in an output of 1, whereas wrong solutions will result in an output of 0.

Example 1:

Input:
N = 7
A[] = {100,180,260,310,40,535,695}
Output:
1
Explanation:
One possible solution is (0 3) (4 6)
We can buy stock on day 0,
and sell it on 3rd day, which will 
give us maximum profit. Now, we buy 
stock on day 4 and sell it on day 6.
Example 2:

Input:
N = 5
A[] = {4,2,2,2,4}
Output:
1
Explanation:
There are multiple possible solutions.
one of them is (3 4)
We can buy stock on day 3,
and sell it on 4th day, which will 
give us maximum profit.

Your Task:
The task is to complete the function stockBuySell() which takes an array A[] and N as input parameters and finds the days of buying and selling stock. The function must return a 2D list of integers containing all the buy-sell pairs. If there is No Profit, return an empty list.

 

Note: Since there can be multiple solutions, the driver code will return 1 if your answer is correct, otherwise, it will return 0. In case there's no profit the driver code will return the string "No Profit" for a correct solution.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


Constraints:
2 ≤ N ≤ 106
0 ≤ A[i] ≤ 106
*/

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the maximum profit
// that can be made after buying and
// selling the given stocks
int maxProfit(int price[], int start, int end)
{

    // If the stocks can't be bought
    if (end <= start)
        return 0;

    // Initialise the profit
    int profit = 0;

    // The day at which the stock
    // must be bought
    for (int i = start; i < end; i++) {

        // The day at which the
        // stock must be sold
        for (int j = i + 1; j <= end; j++) {

            // If buying the stock at ith day and
            // selling it at jth day is profitable
            if (price[j] > price[i]) {

                // Update the current profit
                int curr_profit = price[j] - price[i]
                                  + maxProfit(price, start, i - 1)
                                  + maxProfit(price, j + 1, end);

                // Update the maximum profit so far
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

// Driver code
int main()
{
    int price[] = { 100, 180, 260, 310,
                    40, 535, 695 };
    int n = sizeof(price) / sizeof(price[0]);

    cout << maxProfit(price, 0, n - 1);

    return 0;
}
