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
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, P;
    cin >> N >> P;

    dynamic_modint<0>::set_mod((int) P);
    auto dp = vector(N, vector(N + 1, dynamic_modint<0>()));
    dp[0][0] = dynamic_modint<0>(26) / 25;
    auto acc = vector(N, vector(N + 1, dynamic_modint<0>()));

    auto powten = array { 1, 10, 100, 1000, 10000 };
    i64 M = (i64) log10(N);
    for (i64 i = 0; i < N; i++) {
        for (i64 j = 0; j <= N; j++) {
            for (i64 k = 0; k <= M && k + 2 <= i; k++) {
                i64 maxj = max(i64(), j - powten[k] + 1);
                i64 minj = max(i64(), j - powten[k + 1] + 1);
                i64 ni = i - k - 2;
                dp[i][j] += (acc[ni][maxj] - acc[ni][minj]) * 25;
            }
            if (j < N) {
                acc[i][j + 1] = acc[i][j] + dp[i][j];
            }
        }
    }
    auto ans = dynamic_modint<0>();
    for (i64 i = 0; i < N; i++) ans += dp[i][N];
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
