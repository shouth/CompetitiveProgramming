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
    i64 N, Q;
    cin >> N >> Q;
    auto X = vector<i64>(N);
    for (auto &e : X) cin >> e;

    auto t = vector(N, vector<i64>());
    for (i64 i = 0; i < N - 1; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        t[A].emplace_back(B);
        t[B].emplace_back(A);
    }

    auto ans = vector(N, vector<i64>());
    auto dfs = [&](const auto &self, i64 node, i64 from) -> vector<i64> {
        auto res = vector(20, -INF);
        res[0] = X[node];
        for (auto &next : t[node]) {
            if (next == from) continue;
            auto tmp = self(self, next, node);
            res.insert(end(res), begin(tmp), end(tmp));
            inplace_merge(begin(res), begin(res) + 20, end(res), greater());
            res.resize(20);
        }
        return ans[node] = res;
    };
    dfs(dfs, 0, -1);

    for (i64 i = 0; i < Q; i++) {
        i64 V, K;
        cin >> V >> K, V--, K--;
        cout << ans[V][K] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
