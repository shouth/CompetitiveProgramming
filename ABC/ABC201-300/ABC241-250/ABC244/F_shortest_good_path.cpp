#include<bits/stdc++.h>
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
    i64 N, M;
    cin >> N >> M;

    auto graph = vector(N, vector<i64>());
    for (i64 i = 0; i < M; i++) {
        i64 u, v;
        cin >> u >> v, u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    auto dist = vector(1ll << N, vector(N, -1ll));
    auto q = queue<p64>();
    for (i64 i = 0; i < N; i++) {
        dist[0][i] = 0;
        i64 pat = 1ll << i;
        dist[pat][i] = 1;
        q.emplace(pat, i);
    }
    while (!q.empty()) {
        auto [ pat, on ] = q.front();
        q.pop();

        for (auto e : graph[on]) {
            i64 npat = pat ^ (1ll << e);
            if (dist[npat][e] != -1) continue;
            dist[npat][e] = dist[pat][on] + 1;
            q.emplace(npat, e);
        }
    }

    i64 ans = 0;
    for (auto &e : dist) {
        ans += *min_element(all(e));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
