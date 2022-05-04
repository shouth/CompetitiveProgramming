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
    i64 N, P;
    cin >> N >> P;

    dynamic_modint<0>::set_mod((int) P);
    auto dp = vector(N, vector(2, dynamic_modint<0>()));
    dp[0][0] = dp[1][1] = 1;
    for (i64 i = 0; i < N - 1; i++) {
        for (i64 j = N - 1; j >= 0; j--) {
            dp[j][0] += dp[j][1];
            dp[j][1] = 0;
            if (j - 1 >= 0) {
                dp[j][0] += dp[j - 1][0] * 3;
                dp[j][1] += dp[j - 1][1];
            }
            if (j - 2 >= 0) {
                dp[j][1] += dp[j - 2][0] * 2;
            }
        }
    }
    for (i64 j = 1; j < N; j++) {
        cout << (j == 1 ? "" : " ") << dp[j][0].val();
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
