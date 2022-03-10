#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int64_t modpow(int64_t x, int64_t n, int64_t m = 1) {
    return n == 0 ? m : modpow(x * x % MOD, n >> 1, n & 1 ? m * x % MOD : m);
}

int64_t comb(int64_t n, int64_t k) {
    if (n - k < k) k = n - k;

    int64_t res0 = 1, res1 = 1;
    for (int i = n; i > n-k; i--) {
        res0 = res0 * i % MOD;
    }
    for (int i = k; i > 0; i--) {
        res1 = res1 * i % MOD;
    }

    return res0 * modpow(res1, MOD-2) % MOD;
}

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;

    cout << ((modpow(2, n) - 1 - comb(n, a) + MOD) % MOD - comb(n, b) + MOD) % MOD << endl;;
}
