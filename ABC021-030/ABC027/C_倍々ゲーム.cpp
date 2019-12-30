#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    int64_t d = log2(n);
    int64_t x = 1;
    while (true) {
        x = 2 * x + (d + 1) % 2;
        if (x > n) {
            cout << "Aoki" << endl;
            break;
        }
        x = 2 * x + d % 2;
        if (x > n) {
            cout << "Takahashi" << endl;
            break;
        }
    }
}
