#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n;
    cin >> n;

    map<int64_t, int64_t> factors;
    for (int64_t i = 2; i <= n; i++) {
        for (int64_t j = 2, d = i; d != 1; j++) {
            while (d % j == 0) {
                d /= j;
                factors[j]++;
            }
        }
    }

    int64_t ans = 1;
    for (auto& e : factors) ans = ans * (e.second + 1) % MOD;
    cout << ans << endl;
}
