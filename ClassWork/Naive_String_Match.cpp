#include <iostream>
using namespace std;

int naive(string str, string pat) {
    int patLen = pat.length();
    int strLen = str.length();
    
    int a = -1;
    int arr[strLen - patLen];
    int index = 0;
    for (int i = 0; i < (strLen - patLen + 1); i++) {
        int j;
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pat[j]) {
                break;
            }
        }
        if (j == patLen) {
            a = 1;
            arr[index++] = i;
        }
    }
    if(a == -1){
        cout << a;
    } else {
        for(int k = 0; k < index; k++){
            cout << arr[k];
            if (k != index){
                cout << ",";
            }
        }
    }
}

int main() {
    string pat, str;
    cin >> str;
    cin >> pat;

    int index = naive(str, pat);

    return 0;
}