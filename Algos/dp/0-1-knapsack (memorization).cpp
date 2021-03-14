// 0-1 knapsack (only dp values) (memorization)
// Copied from GFG

#include <bits/stdc++.h>
using namespace std;

int knapSackRec(int w, int wt[], int val[],
                int i, int** dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][w] != -1)
        return dp[i][w];

    if (wt[i] > w) {

        // Store the value of function call
        // stack in table before return
        dp[i][w] = knapSackRec(w, wt, val, i - 1, dp);
        return dp[i][w];
    }
    else {

        // Store value in a table before return
        dp[i][w] = max(
            val[i] + knapSackRec(w - wt[i], wt, val, i - 1, dp),
            knapSackRec(w, wt, val, i - 1, dp));

        // Return value of table after storing
        return dp[i][w];
    }
}

int knapSack(int w, int wt[], int val[], int n)
{
    // double pointer to declare the
// table dynamically
    int** dp;
    dp = new int*[n];

    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[w + 1];

    // loop to initially filled the
// table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < w + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(w, wt, val, n - 1, dp);
}
