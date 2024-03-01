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
    i64 N, M, K;
    cin >> N >> M >> K;

    auto dp = vector(N + 1, vector(K + 1, m64()));
    dp[0][0] = 1;
    for (i64 i = 0; i < N; i++) {
        for (i64 j = 0; j <= K; j++) {
            for (i64 k = 1; k <= M && j - k >= 0; k++) {
                dp[i + 1][j] += dp[i][j - k];
            }
        }
    }
    cout << reduce(all(dp[N])).val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
