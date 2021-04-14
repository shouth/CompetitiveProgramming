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
    i64 N, M, Q;
    cin >> N >> M >> Q;

    vector<p64> VW(N);
    for (auto &[ V, W ] : VW) cin >> W >> V;
    sort(all(VW), greater<>());

    vector<i64> X(M);
    for (auto &e : X) cin >> e;

    for (i64 _ = 0; _ < Q; _++) {
        i64 L, R;
        cin >> L >> R, L--;

        vector<i64> remain;
        for (i64 i = 0; i < L; i++) remain.push_back(X[i]);
        for (i64 i = R; i < M; i++) remain.push_back(X[i]);
        sort(all(remain));

        i64 m = remain.size();
        vector<i64> used(m);
        i64 ans = 0;
        for (auto &[ V, W ] : VW) {
            for (i64 i = 0; i < m; i++) {
                if (!used[i] && remain[i] >= W) {
                    used[i] = 1;
                    ans += V;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
