#include <iostream>
#include <climits>
using namespace std;

int matrixChainOrder(int p[], int n) {
    int m[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of dimensions: ";
    cin >> n;

    int dimensions[n];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i < n; i++) {
        cin >> dimensions[i];
    }

    int minMultiplications = matrixChainOrder(dimensions, n);

    cout << "Minimum number of multiplications needed: " << minMultiplications << endl;

    return 0;
}
