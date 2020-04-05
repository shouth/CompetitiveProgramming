#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int64_t modinv(int64_t x) {
    int64_t n = MOD - 2, res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t t = modinv((a * (b + c) % MOD - b * c % MOD + MOD) % MOD) % MOD;
    cout << a * b % MOD * t % MOD - 1 << " " << a * c % MOD * t % MOD - 1 << endl;
}
