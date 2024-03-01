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
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

i64 n, m;
i64 s, k;
vector<vector<i64>> tdist;
map<p64, i64> dp;

i64 dfs(i64 from, i64 remain) {
    if (remain == 0) return 0;
    if (dp.find({from, remain}) != dp.end()) return dp[{from, remain}];
    i64 res = INF;
    for (i64 i = 0; i < k; i++) {
        if ((remain >> i) & 1) res = min(res, tdist[from][i] + dfs(i, remain - (1l << i)));
    }
    return dp[{from, remain}] = res;
}

void solve() {
    cin >> n >> m;
    vector<vector<i64>> g(n);
    for (i64 i = 0; i < m; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    cin >> s >> k, s--;
    vector<i64> t(k);
    for (auto& e : t) cin >> e, e--;
    t.emplace_back(s);

    tdist.assign(k + 1, vector<i64>(k + 1));
    for (i64 i = 0; i < k + 1; i++) {
        vector<i64> dist(n, -1);
        dist[t[i]] = 0;
        queue<i64> q;
        q.emplace(t[i]);
        while (!q.empty()) {
            i64 cur = q.front(); q.pop();
            for (auto& f : g[cur]) {
                if (dist[f] != -1) continue;
                dist[f] = dist[cur] + 1;
                q.emplace(f);
            }
        }

        for (i64 j = 0; j < k + 1; j++) {
            tdist[i][j] = tdist[j][i] = dist[t[j]];
        }
    }

    cout << dfs(k, (1l << k) - 1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
