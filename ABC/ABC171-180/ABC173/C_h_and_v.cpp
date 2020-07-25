#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    for (auto& e : c) cin >> e;

    i64 ans = 0;
    for (i64 selh = 0; selh < (1 << h); selh++) {
        for (i64 selw = 0; selw < (1 << w); selw++) {
            i64 cnt = 0;
            for (i64 i = 0; i < h; i++) {
                for (i64 j = 0; j < w; j++) {
                    if (((selh >> i) & 1) || ((selw >> j) & 1)) continue;
                    if (c[i][j] == '#') cnt++;
                }
            }
            if (cnt == k) ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
