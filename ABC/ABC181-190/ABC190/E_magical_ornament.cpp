#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;

    vector<vector<i64>> g(N);
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        g[A].emplace_back(B);
        g[B].emplace_back(A);
    }

    i64 K;
    cin >> K;
    vector<i64> C(K);
    for (auto& e : C) cin >> e, e--;

    auto distall = vector(K, vector<i64>(K, INF));
    for (i64 i = 0; i < K; i++) {
        queue<i64> q;
        q.push(C[i]);
        vector<i64> dists(N, INF);
        dists[C[i]] = 0;

        while (!q.empty()) {
            i64 t = q.front();
            q.pop();

            for (auto &e : g[t]) {
                if (dists[e] != INF) continue;
                dists[e] = dists[t] + 1;
                q.push(e);
            }
        }

        for (i64 j = i; j < K; j++) {
            distall[i][j] = distall[j][i] = dists[C[j]];
        }
    }

    for (i64 k = 0; k < K; k++) {
        for (i64 i = 0; i < K; i++) {
            for (i64 j = 0; j < K; j++) {
                distall[i][j] = min(distall[i][j], distall[i][k] + distall[k][j]);
            }
        }
    }

    auto dp = vector(1 << K, vector(K, -1l));
    auto dfs = [&](auto f, i64 used, i64 last) {
        if (used == (1 << K) - 1) return 0l;
        if (dp[used][last] != -1) return dp[used][last];

        i64 res = INF;
        for (i64 i = 0; i < K; i++) {
            if ((used >> i) & 1) continue;
            res = min(res, f(f, used | (1 << i), i) + distall[last][i]);
        }
        return dp[used][last] = res;
    };

    i64 ans = INF;
    for (i64 i = 0; i < K; i++) {
        ans = min(ans, dfs(dfs, 1 << i, i));
    }
    cout << (ans != INF ? ans + 1 : -1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
