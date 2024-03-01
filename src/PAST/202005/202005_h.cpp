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

using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

i64 n, l;
vector<i64> hurdle;
i64 trun, tjump, tblock;

vector<i64> dp;

i64 dfs(i64 x) {
    if (dp[x] != -1) return dp[x];

    dp[x] = dfs(x - 1) + tblock * hurdle[x - 1] + trun;
    if (x - 2 >= 0) dp[x] = min(dp[x], dfs(x - 2) + tblock * hurdle[x - 2] + trun + tjump);
    if (x - 4 >= 0) dp[x] = min(dp[x], dfs(x - 4) + tblock * hurdle[x - 4] + trun + tjump * 3);

    return dp[x];
}

void solve() {
    cin >> n >> l;
    hurdle.assign(l + 1, 0);
    for (i64 i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        hurdle[x] = 1;
    }

    cin >> trun >> tjump >> tblock;
    dp.assign(l + 1, -1);
    dp[0] = 0;
    i64 ans = dfs(l);
    for (i64 i = 1; i <= 3; i++) {
        if (l - i >= 0) ans = min(ans, dfs(l - i) + tblock * hurdle[l - i] + trun / 2 + tjump / 2 + tjump * (i - 1));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
