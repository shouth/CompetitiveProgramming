#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

vector<int64_t> fac, ifac;

int64_t modpow(int64_t x, int64_t n) {
    int64_t res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

int64_t modcom(int64_t n, int64_t m) {
    if (n == 0 && m == 0) return 1;
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}

int main() {
    int64_t r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;

    fac.assign(x*y + 1, 1);
    ifac.assign(x*y + 1, 1);
    for (int64_t i = 0; i < x*y; i++) {
        fac[i+1] = fac[i] * (i+1) % MOD;
        ifac[i+1] = ifac[i] * modpow(i+1, MOD-2) % MOD;
    }

    int64_t frame = 0;
    for (int64_t i = 0; i < (1 << 4); i++) {
        int64_t room = max(0l, x - __builtin_popcount(i & 0b0011)) * max(0l, y - __builtin_popcount(i & 0b1100));
        int64_t locate = modcom(room, d + l) * modcom(d + l, d) % MOD;
        frame = (frame + (__builtin_parity(i) ? -1 : 1) * locate + MOD) % MOD;
    }

    cout << frame * (r-x+1) % MOD * (c-y+1) % MOD << endl;
}
