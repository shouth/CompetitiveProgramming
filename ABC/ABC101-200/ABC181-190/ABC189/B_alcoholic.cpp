#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, X;
    cin >> N >> X;

    i64 total = 0;
    i64 ans = -1;
    for (i64 i = 0; i < N; i++) {
        i64 V, P;
        cin >> V >> P;
        total += V * P;
        if (ans == -1 && total > X * 100) ans = i + 1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
