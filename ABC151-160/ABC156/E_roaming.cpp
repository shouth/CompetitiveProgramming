#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;
constexpr int64_t SIZE = 2e5;

array<int64_t, SIZE+10> fac, ifac;

int64_t modpow(int64_t x, int64_t n, int64_t m = 1) {
    return n == 0 ? m : modpow(x * x % MOD, n >> 1, n & 1 ? m * x % MOD : m);
}

int64_t comb(int64_t n, int64_t k) {
    return n == 0 && k == 0 ? 1
        : n < k || n < 0 ? 0
        : fac[n] * ifac[k] % MOD * ifac[n-k] % MOD;
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int64_t i = 0; i+1 < SIZE + 10; i++) {
        fac[i+1] = fac[i] * (i+1) % MOD;
        ifac[i+1] = ifac[i] * modpow(i+1, MOD-2) % MOD;
    }
    
    int64_t n, k;
    cin >> n >> k;
    if (k > n) k = n;

    int64_t ans = 0;
    for (int64_t x = 0; x < n; x++) {
        ans += comb(n, x) * comb(n+x-1, x-1) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
