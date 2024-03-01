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

#include<atcoder/all>

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
    auto tree = vector<vector<p64>>(N);
    for (i64 _ = 0; _ < N - 1; _++) {
        i64 u, v, w;
        cin >> u >> v >> w, u--, v--;
        tree[u].emplace_back(v, w);
        tree[v].emplace_back(u, w);
    }

    auto dists = vector<i64>(N, -1);
    auto q = queue<p64>();
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [ node, dist ] = q.front();
        q.pop();

        if (dists[node] != -1) continue;
        dists[node] = dist;

        for (auto [ next, cost ] : tree[node]) {
            if (dists[next] != -1) continue;
            q.emplace(next, dist ^ cost);
        }
    }

    m64 ans = 0;
    for (i64 i = 0; i < 60; i++) {
        auto cnt = vector<i64>(2);
        for (i64 j = 0; j < N; j++) cnt[(dists[j] >> i) & 1]++;
        ans += cnt[0] * cnt[1] * m64(1ll << i);
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
