#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    vector<p64> xy(n);
    for (auto& e : xy) cin >> e.first >> e.second;

    map<p64, i64> cnt;
    cnt[{ INF, INF }] = 0;
    for (auto& e : xy) {
        for (auto& f : xy) {
            if (e == f) continue;
            cnt[{ e.first - f.first, e.second - f.second }]++;
        }
    }

    i64 ans = INF;
    for (auto& e : cnt) ans = min(ans, n - e.second);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
