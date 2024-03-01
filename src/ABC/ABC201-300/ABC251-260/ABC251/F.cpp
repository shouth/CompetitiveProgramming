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
#include <atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;

    auto g = vector(N, vector<i64>());
    for (i64 i = 0; i < M; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto visited = vector<bool>(N);
    auto dfs = [&](auto self, i64 cur, i64 from) {
        if (visited[cur]) return;
        if (from != -1) {
            cout << from + 1 << " " << cur + 1 << "\n";
        }

        visited[cur] = 1;
        for (auto &e : g[cur]) {
            if (!visited[e]) self(self, e, cur);
        }
    };
    dfs(dfs, 0, -1);

    visited.assign(N, 0);
    auto q = queue<p64>();
    q.emplace(0, -1);
    while (!q.empty()) {
        auto [ cur, from ] = q.front();
        q.pop();
        if (visited[cur]) continue;
        if (from != -1) {
            cout << from + 1 << " " << cur + 1 << "\n";
        }

        visited[cur] = 1;
        for (auto &e : g[cur]) {
            if (!visited[e]) q.emplace(e, cur);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
