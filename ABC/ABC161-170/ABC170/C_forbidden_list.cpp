#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 x, n;
    cin >> x >> n;
    set<i64> ps;
    for (i64 i = 0; i < n; i++) {
        i64 p;
        cin >> p;
        ps.insert(p);
    }

    i64 ans = INF, dist = INF;
    for (i64 i = 0; i <= 101; i++) {
        if (ps.find(i) != ps.end()) continue;
        if (abs(x - i) >= dist) continue;
        ans = i;
        dist = abs(x - i);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
