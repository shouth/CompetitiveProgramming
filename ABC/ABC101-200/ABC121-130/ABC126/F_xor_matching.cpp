#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 M, K;
    cin >> M >> K;

    if (K >= 1l << M) {
        cout << "-1" << endl;
        return;
    }

    if (M == 0) {
        cout << "0 0" << endl;
        return;
    }

    if (M == 1) {
        cout << (K == 0 ? "0 0 1 1" : "-1") << endl;
        return;
    }

    for (i64 i = 0; i < 1l << M; i++) if (i != K) cout << i << " ";
    cout << K << " ";
    for (i64 i = (1l << M) - 1; i >= 0; i--) if (i != K) cout << i << " ";
    cout << K << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
