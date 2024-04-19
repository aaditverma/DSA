#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMaxMin(const vector<int>& arr, int low, int high, int& maxElement, int& minElement) {

    if (low == high) {
        maxElement = arr[low];
        minElement = arr[low];
        return;
    }

    if (high - low == 1) {
        if (arr[low] > arr[high]) {
            maxElement = arr[low];
            minElement = arr[high];
        } else {
            maxElement = arr[high];
            minElement = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMax, leftMin, rightMax, rightMin;

    findMaxMin(arr, low, mid, leftMax, leftMin);
    findMaxMin(arr, mid + 1, high, rightMax, rightMin);

    maxElement = max(leftMax, rightMax);
    minElement = min(leftMin, rightMin);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxElement, minElement;

    findMaxMin(arr, 0, n - 1, maxElement, minElement);

    cout << "Maximum element: " << maxElement << endl;
    cout << "Minimum element: " << minElement << endl;

    return 0;
}