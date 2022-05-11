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

i64 n, k;
vector<vector<vector<f64>>> dp;

f64 dfs(i64 i, i64 j, i64 b) {
    if (j > k) return 0;
    if (i == n) return b == 0 ? 0 : 1;
    if (dp[i][j][b] != -1.0) return dp[i][j][b];

    f64 res = 0;
    res += max(dfs(i + 1, j + 1, 1), dfs(i + 1, j, 0)) / (i + 1.0);
    res += dfs(i + 1, j, b) * i / (i + 1.0);
    return dp[i][j][b] = res;
}

void solve() {
    cin >> n >> k;
    dp.assign(n + 1, vector<vector<f64>>(k + 1, vector<f64>(2, -1.0)));
    cout << dfs(0, 0, 0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
