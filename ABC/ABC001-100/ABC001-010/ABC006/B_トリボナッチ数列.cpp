#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e4 + 7;

int main() {
    int n;
    cin >> n;
    int a1 = 0, a2 = 0, a3 = 1;
    for (int m = 3; m < n; m++) {
        int aa = (a1 + a2 + a3) % MOD;
        a1 = a2, a2 = a3, a3 = aa;
    }

    cout << (n == 1 ? a1 : n == 2 ? a2 : a3) << endl;
}
