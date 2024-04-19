#include <iostream>
#include <string>

using namespace std;

int main() {
    string string1, string2;
    
    // Read inputs
    cout << "Enter string1: ";
    cin >> string1;
    
    cout << "Enter string2: ";
    cin >> string2;

    int m = string1.length();
    int n = string2.length();

    // Create a table to store lengths of longest common suffixes of substrings
    int dp[m + 1][n + 1];

    // Fill dp[][] in a bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (string1[i - 1] == string2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // If length of LCS is equal to length of string1, it means string1 is embedded in string2
    if (dp[m][n] == m)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
