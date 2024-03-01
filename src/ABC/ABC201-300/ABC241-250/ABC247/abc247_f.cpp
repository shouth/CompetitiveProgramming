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
using m64 = modint998244353;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    auto P = vector<i64>(N);
    for (auto &e : P) cin >> e, e--;
    auto Q = vector<i64>(N);
    for (auto &e : Q) cin >> e, e--;

    auto g = vector(N, vector<i64>());
    for (i64 i = 0; i < N; i++) {
        i64 p = P[i], q = Q[i];
        g[p].emplace_back(q);
        if (p != q) g[q].emplace_back(p);
    }

    auto dp = vector<m64>(N + 1);
    dp[0] = 1, dp[1] = 2;
    for (i64 i = 1; i < N; i++) {
        dp[i + 1] = dp[i] + dp[i - 1];
    }
    for (i64 i = N; i >= 3; i--) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    dp[0] = 1, dp[1] = 1, dp[2] = 3;

    m64 ans = 1;
    auto visited = vector<bool>(N);
    for (i64 n = 0; n < N; n++) {
        if (visited[n]) continue;

        i64 cnt = 0;
        auto q = queue<i64>();
        q.emplace(n);
        while (!q.empty()) {
            i64 t = q.front();
            q.pop();

            if (visited[t]) continue;
            visited[t] = 1;
            cnt++;

            for (auto &e : g[t]) {
                if (visited[e]) continue;
                q.emplace(e);
            }
        }
        ans *= dp[cnt];
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
