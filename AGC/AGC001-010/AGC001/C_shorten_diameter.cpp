#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

i64 n, k;
vector<vector<i64>> graph;

i64 dfs(i64 current, i64 from, i64 depth) {
    if (depth == k / 2) return 1;
    i64 res = 1;
    for (auto& e : graph[current]) {
        if (e == from) continue;
        res += dfs(e, current, depth + 1);
    }
    return res;
}

void solve() {
    cin >> n >> k;
    graph.assign(n, {});

    vector<p64> edges(n - 1);
    for (i64 i = 0; i < n - 1; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        edges[i] = { a, b };
    }

    i64 ans = INF;
    if (k % 2) {
        for (auto& e : edges) {
            ans = min(ans, n - (dfs(e.first, e.second, 0) + dfs(e.second, e.first, 0)));
        }
    } else {
        for (i64 i = 0; i < n; i++) {
            ans = min(ans, n - dfs(i, -1, 0));
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
