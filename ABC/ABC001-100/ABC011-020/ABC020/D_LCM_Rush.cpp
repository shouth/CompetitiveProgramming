#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> gcds;
    for (int64_t m = 1; m * m <= k; m++) {
        if (k % m != 0) continue;
        gcds.push_back(m);
        if (m * m != k) gcds.push_back(k / m);
    }

    int64_t ans = 0;
    for (auto& e : gcds) {
        int64_t nn = n / e, kk = k / e;
        vector<int64_t> primefactors;
        for (int64_t m = 2; m * m <= kk; m++) {
            if (kk % m == 0) primefactors.push_back(m);
            while (kk % m == 0) kk /= m;
        }
        if (kk != 1) primefactors.push_back(kk);

        int64_t kinds = primefactors.size();
        int64_t tmp = 0;
        for (int64_t select = 0; select < (1 << kinds); select++) {
            int64_t divisor = 1;
            for (int64_t i = 0; i < kinds; i++) {
                if ((select >> i) & 1) divisor *= primefactors[i];
            }
            int64_t used = bitset<32>(select).count();
            int64_t lim = nn / divisor;
            tmp += divisor * (lim * (lim + 1) / 2 % MOD) % MOD * (used % 2 ? -1 : 1) + MOD;
            tmp %= MOD;
        }
        ans += tmp * k % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
