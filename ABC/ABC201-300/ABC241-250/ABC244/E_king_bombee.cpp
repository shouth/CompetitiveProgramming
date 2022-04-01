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
using m64 = modint998244353;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M, K, S, T, X;
    cin >> N >> M >> K >> S >> T >> X, S--, T--, X--;
    auto g = vector<vector<i64>>(N);
    for (i64 _ = 0; _ < M; _++) {
        i64 U, V;
        cin >> U >> V, U--, V--;
        g[U].emplace_back(V);
        g[V].emplace_back(U);
    }

    auto dp = vector(2, vector(N, vector<m64>(2)));
    dp[0][S][0] = 1;
    for (i64 i = 0; i < K; i++) {
        for (i64 j = 0; j < N; j++) {
            dp[(i + 1) & 1][j][0] = dp[(i + 1) & 1][j][1] = 0;
            for (auto &k : g[j]) {
                for (i64 l = 0; l < 2; l++) {
                    dp[(i + 1) & 1][j][l ^ (j == X)] += dp[i & 1][k][l];
                }
            }
        }
    }
    cout << dp[K & 1][T][0].val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
