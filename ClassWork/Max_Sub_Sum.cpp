#include <iostream>
#include <climits>

using namespace std;

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int sum = 0;
    int leftSum = INT_MIN;
    
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    int rightSum = INT_MIN;
    
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, high);
    int crossSum = maxCrossingSum(arr, low, mid, high);

    return max(max(leftSum, rightSum), crossSum);
}

int main() {
    int num_of_elements;
    cout << "Enter the number of elements: ";
    cin >> num_of_elements;

    int Array[num_of_elements];
    cout << "Enter the elements:" << endl;

    for (int i = 0; i < num_of_elements; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> Array[i];
    }

    int result = maxSubarraySum(Array, 0, num_of_elements - 1);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

