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
    i64 N, K;
    cin >> N >> K;
    auto S = vector<string>(N);
    for (auto &e : S) cin >> e;

    i64 ans = 0;
    for (i64 i = 0; i < (1 << N); i++) {
        auto cnt = map<char, i64>();
        for (i64 j = 0; j < N; j++) {
            if (((i >> j) & 1) == 0) continue;
            for (auto &e : S[j]) cnt[e]++;
        }
        i64 cand = 0;
        for (auto &[ _, v ] : cnt) {
            if (v == K) cand++;
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
