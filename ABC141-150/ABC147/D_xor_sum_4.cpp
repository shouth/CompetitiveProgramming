#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;
    for (int64_t i = 0; i < 60; i++) {
        int64_t c = 0;
        for (auto& e : a) c += ((e >> i) & 1);
        ans += (1l << i) % MOD * c % MOD * (n - c) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
