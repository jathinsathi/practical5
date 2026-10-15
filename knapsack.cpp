#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns the maximum value that can be put in a knapsack of capacity W
int knapsack01(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // dp[i][w] stores the max value for 'i' items and capacity 'w'
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            // If the weight of the current item is less than or equal to the capacity
            if (weights[i - 1] <= w) {
                // Max of including the item or excluding it
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w]);
            } else {
                // Exclude the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // The final answer is in the bottom-right corner
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;
    int n = values.size();

    cout << "Maximum value in Knapsack = " << knapsack01(W, weights, values, n) << endl;

    return 0;
}
