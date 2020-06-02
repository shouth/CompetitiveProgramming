#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    if (find(all(a), 0) != end(a)) {
        cout << 0 << endl;
        return;
    }

    i64 ans = 1;
    for (auto& e : a) {
        if (ans > (i64) 1e18 / e) {
            cout << -1 << endl;
            return;
        }
        ans *= e;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
