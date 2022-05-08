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
    i64 N;
    cin >> N;

    auto dp = vector(2, vector<m64>(11));
    for (i64 i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for (i64 i = 1; i < N; i++) {
        for (i64 j = 1; j <= 9; j++) {
            dp[(i + 1) & 1][j] = dp[i & 1][j - 1] + dp[i & 1][j] + dp[i & 1][j + 1];
        }
    }
    cout << reduce(all(dp[N & 1])).val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
