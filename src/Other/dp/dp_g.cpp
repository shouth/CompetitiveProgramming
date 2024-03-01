#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

vector<i64> dp;
vector<vector<i64>> g;

i64 dfs(i64 i) {
    if (dp[i] != -1) return dp[i];

    i64 res = 0;
    for (auto& e : g[i]) res = max(res, dfs(e) + 1);
    return dp[i] = res;
}

void solve() {
    i64 n, m;
    cin >> n >> m;

    g.resize(n);
    for (i64 i = 0; i < m; i++) {
        i64 x, y;
        cin >> x >> y, x--, y--;
        g[x].emplace_back(y);
    }

    dp.resize(n, -1);
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) ans = max(ans, dfs(i));
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
