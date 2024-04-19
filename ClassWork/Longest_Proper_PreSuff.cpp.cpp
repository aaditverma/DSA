#include <iostream>
#include <vector>
#include <string>

using namespace std;

void lps_func(string txt, vector<int>& Lps) {
    Lps[0] = 0; // Lps[0] is always 0
    int len = 0;
    int i = 1;
    while (i < txt.length()) {
        if (txt[i] == txt[len]) { // Case 1
            len++;
            Lps[i] = len;
            i++;
            continue;
        } else { // Case 2
            if (len == 0) { // Subcase 1
                Lps[i] = 0;
                i++;
                continue;
            } else { // Subcase 2
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

int main() {
    string text;
    cout << "Enter a string: ";
    cin >> text;

    vector<int> Lps(text.length());
    lps_func(text, Lps);
    cout << "LPS array is ";
    for (int i = 0; i < text.length(); i++) {
        cout << Lps[i] << " ";
    }

    return 0;
}
