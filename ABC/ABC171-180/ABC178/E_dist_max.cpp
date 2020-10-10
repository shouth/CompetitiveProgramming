#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    vector<p64> xy(N);
    for (auto& [ x, y ] : xy) cin >> x >> y;

    i64 ans = 0;
    sort(all(xy), [](p64 a, p64 b) { return a.first + a.second < b.first + b.second; });
    ans = max(ans, abs(xy.front().first - xy.back().first) + abs(xy.front().second - xy.back().second));
    sort(all(xy), [](p64 a, p64 b) { return a.first - a.second < b.first - b.second; });
    ans = max(ans, abs(xy.front().first - xy.back().first) + abs(xy.front().second - xy.back().second));
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
