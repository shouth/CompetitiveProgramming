#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

i64 h, w;
vector<string> s;
vector<vector<i64>> dp;

i64 dfs(i64 y, i64 x) {
    if (y >= h || x >= w) return 1;
    if (s[y][x] == '#') return 1;
    if (dp[y][x] != -1) return dp[y][x];
    return dp[y][x] = !dfs(y + 1, x) || !dfs(y, x + 1) || !dfs(y + 1, x + 1);
}

void solve() {
    cin >> h >> w;
    s.assign(h, {});
    for (auto& e : s) cin >> e;
    dp.assign(h, vector<i64>(w, -1));
    cout << (dfs(0, 0) ? "First" : "Second") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
