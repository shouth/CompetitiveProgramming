#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;

i64 h, w;
vector<string> s;
vector<vector<i64>> dp;

i64 dfs(i64 y = 0, i64 x = 0) {
    if (dp[y][x] != -1) return dp[y][x];
    i64 res = INT64_MAX / 2;
    if (y + 1 < h) res = min(res, (s[y][x] == '#' && s[y + 1][x] == '.') + dfs(y + 1, x));
    if (x + 1 < w) res = min(res, (s[y][x] == '#' && s[y][x + 1] == '.') + dfs(y, x + 1));
    return dp[y][x] = res;
}

void solve() {
    cin >> h >> w;
    s.assign(h, "");
    for (auto& e : s) cin >> e;
    dp.assign(h, vector<i64>(w, -1));
    dp[h - 1][w - 1] = s[h - 1][w - 1] == '#';
    cout << dfs() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
