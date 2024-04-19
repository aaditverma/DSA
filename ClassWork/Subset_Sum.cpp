#include <iostream>
#include <vector>

using namespace std;

void backtrackSubset(int i, int n, int set[], int targetSum, vector<int>& subset) {
    if (targetSum == 0 && subset.size() == n) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    if (i == n || targetSum < 0 || subset.size() > n) {
        return;
    }

    subset.push_back(1);
    backtrackSubset(i + 1, n, set, targetSum - set[i], subset);
    subset.pop_back();
    
    subset.push_back(0);
    backtrackSubset(i + 1, n, set, targetSum, subset);
    subset.pop_back();
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> set[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> subset;
    backtrackSubset(0, n, set, targetSum, subset);

    return 0;
}
