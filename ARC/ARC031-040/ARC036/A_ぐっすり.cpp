#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<i64> t(n + 1);
    for (i64 i = 1; i <= n; i++) cin >> t[i];
    partial_sum(all(t), begin(t));
    for (i64 i = 0; i + 3 <= n; i++) {
        if (t[i + 3] - t[i] < k) {
            cout << i + 3 << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
