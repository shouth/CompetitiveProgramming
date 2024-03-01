#include <bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

vector<int64_t> fac(2001), finv(2001);

int64_t modpow(int64_t x, int64_t m) {
    int64_t ans = 1;
    while (m != 0) {
        if (m & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        m = m >> 1;
    }
    return ans;
}

int64_t combi(int64_t a, int64_t b) {
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    fac[0] = 1;
    finv[0] = 1;

    for (int i = 1; i <= 2000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        finv[i] = finv[i - 1] * modpow(i, MOD - 2) % MOD;
    }

    for (int i = 1; i <= k; i++) {
        int64_t ans = combi(n - k + 1, i) * combi(k - 1, i - 1) % MOD;
        cout << ans << endl;
    }
}
