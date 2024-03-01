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
    i64 N;
    cin >> N;
    auto t = vector(N, vector<i64>());
    for (i64 i = 0; i < N - 1; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        t[u].emplace_back(v);
        t[v].emplace_back(u);
    }

    i64 x = 1;
    auto ans = vector<p64>(N);
    auto dfs = [&](auto &self, i64 node, i64 from) -> p64 {
        p64 ret = { INF, -INF };
        for (auto &next : t[node]) {
            if (next == from) continue;
            auto [ minx, maxx ] = self(self, next, node);
            auto &[ retmin, retmax ] = ret;
            retmax = max(retmax, maxx);
            retmin = min(retmin, minx);
        }

        if (ret == p64 { INF, -INF }) {
            ret = { x, x };
            x++;
        }
        return ans[node] = ret;
    };

    dfs(dfs, 0, -1);
    for (auto &[ L, R ] : ans) {
        cout << L << " " << R << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
