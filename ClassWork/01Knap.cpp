#include <iostream>
#include <vector>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack(int W, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the weight and value of each item:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].value;
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value that can be obtained: " << knapsack(W, items) << endl;

    return 0;
}
