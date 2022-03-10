#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int64_t modpow(int64_t x, int64_t n, int64_t m = 1) {
    return n == 0 ? m : modpow(x * x % MOD, n >> 1, n & 1 ? m * x % MOD : m);
}

int main() {
    int64_t n;
    cin >> n;
    int64_t g = 1;
    vector<int64_t> a(n);
    map<int64_t, int64_t> lcmprimefactors;
    for (auto& e : a) {
        int64_t f;
        cin >> e, f = e;
        map<int64_t, int64_t> primefactors;
        for (int64_t m = 2; m <= sqrt(e) && f != 1; m++) {
            while (f % m == 0) f /= m, primefactors[m]++;
        }
        if (f != 1) primefactors[f]++;

        for (auto& f : primefactors) {
            int64_t factor, number;
            tie(factor, number) = f;
            lcmprimefactors[factor] = max(lcmprimefactors[factor], number);
        }
    }

    int64_t l = 1;
    for (auto& f : lcmprimefactors) {
        l *= modpow(f.first, f.second);
        l %= MOD;
    }

    int64_t ans = 0;
    for (auto& e : a) {
        int64_t tmp = l;
        int64_t f = e;
        map<int64_t, int64_t> primefactors;
        for (int64_t m = 2; m <= sqrt(e) && f != 1; m++) {
            while (f % m == 0) f /= m, primefactors[m]++;
        }
        if (f != 1) primefactors[f]++;
        for (auto& e : primefactors) {
            tmp *= modpow(modpow(e.first, e.second), MOD-2);
            tmp %= MOD;
        }

        ans += tmp;
        ans %= MOD;
    }

    cout << ans << endl;
}
