#include <iostream>
#include <cmath>

using namespace std;

long long karatsuba(long long x, long long y) {
    if (x < 10 || y < 10) {
        return x * y;
    } else {

        int n = max(to_string(x).length(), to_string(y).length()) / 2;
        long long a = x / pow(10, n);
        long long b = x % (int)pow(10, n);
        long long c = y / pow(10, n);
        long long d = y % (int)pow(10, n);

        long long ac = karatsuba(a, c);
        long long bd = karatsuba(b, d);
        long long ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

        return ac * pow(10, 2 * n) + ad_plus_bc * pow(10, n) + bd;
    }
}

int main() {
    long long x, y;

    cout << "Enter the first number: ";
    cin >> x;

    cout << "Enter the second number: ";
    cin >> y;

    cout << "Result of multiplication: " << karatsuba(x, y) << endl;

    return 0;
}
