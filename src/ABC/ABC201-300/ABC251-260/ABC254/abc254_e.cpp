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
        i64 a, b;
        cin >> a >> b, a--, b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    i64 Q;
    cin >> Q;
    for (i64 _ = 0; _ < Q; _++) {
        i64 x, k;
        cin >> x >> k, x--;

        auto dist = map<i64, i64>();
        auto q = queue<i64>();
        q.emplace(x);
        i64 ans = 0;
        while (!q.empty()) {
            i64 t = q.front();
            q.pop();

            ans += t + 1;
            if (dist[t] == k) continue;

            for (auto e : g[t]) {
                if (dist.count(e)) continue;
                dist[e] = dist[t] + 1;
                q.emplace(e);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
