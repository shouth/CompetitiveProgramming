#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7, S = 1e5 + 100;
vector<int64_t> fac(S), ifac(S);

int64_t mpow(int64_t x, int64_t n) {
    int64_t res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int64_t combi(int64_t n, int64_t k) {
    return fac[n] * (ifac[k] * ifac[n-k] % MOD) % MOD;
}

int main() {
    int64_t n, m;
    cin >> n >> m;

    fac[0] = ifac[0] = 1;
    for (int i = 0; i + 1 < S; i++) {
        fac[i+1] = fac[i] * (i+1) % MOD;
        ifac[i+1] = ifac[i] * mpow(i+1, MOD-2) % MOD;
    }

    map<int64_t, int64_t> f;
    for (int i = 2, l = sqrt(m) + 1; i <= l; i++) {
        while (m % i == 0) f[i]++, m /= i;
    }
    f[m]++;

    int64_t ans = 1;
    for (auto e : f) {
        ans = ans * combi(e.second + n - 1, e.second) % MOD;
    }

    cout << ans << endl;
}
