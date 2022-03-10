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
    vector<p64> conds(M);
    for (auto& [ A, B ] : conds) cin >> A >> B;

    i64 K;
    cin >> K;
    vector<p64> poss(K);
    for (auto& [ C, D ] : poss) cin >> C >> D;

    bitset<128> bs;
    i64 ans = 0;
    for (i64 i = 0; i < (1 << K); i++) {
        i64 can = 0;
        for (i64 j = 0; j < K; j++) {
            auto& [ C, D ] = poss[j];
            bs.set((i >> j) & 1 ? C : D);
        }
        for (i64 j = 0; j < M; j++) {
            auto& [ A, B ] = conds[j];
            can += bs[A] && bs[B];
        }
        ans = max(ans, can);
        bs.reset();
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
