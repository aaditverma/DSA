#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Preprocess the pattern to calculate the prefix function
vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.size();
    vector<int> prefix(m, 0);
    int k = 0;
    for (int q = 1; q < m; ++q) {
        while (k > 0 && pattern[k] != pattern[q]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[q]) {
            ++k;
        }
        prefix[q] = k;
    }
    return prefix;
}

// KMP string matching algorithm
vector<int> kmpSearch(const string& text, const string& pattern) {
    vector<int> prefix = computePrefixFunction(pattern);
    int n = text.size();
    int m = pattern.size();
    vector<int> matches;
    int q = 0;
    for (int i = 0; i < n; ++i) {
        while (q > 0 && pattern[q] != text[i]) {
            q = prefix[q - 1];
        }
        if (pattern[q] == text[i]) {
            ++q;
        }
        if (q == m) {
            matches.push_back(i - m + 1);
            q = prefix[q - 1];
        }
    }
    return matches;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    vector<int> indices = kmpSearch(text, pattern);

    if (indices.empty()) {
        cout << -1 << endl;
    } else {
        for (size_t i = 0; i < indices.size(); ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << indices[i];
        }
        cout << endl;
    }

    return 0;
}
