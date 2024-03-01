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
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

vector<vector<i64>> dp;
vector<i64> a;
i64 n;

i64 dfs(i64 l, i64 r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l + 1 == r) return 0;

    i64 res = INF;
    for (i64 i = l + 1; i < r; i++) {
        res = min(res, dfs(l, i) + dfs(i, r) + a[r] - a[l]);
    }
    return dp[l][r] = res;
}

void solve() {
    cin >> n;
    a.resize(n + 1);
    for (i64 i = 1; i <= n; i++) cin >> a[i];
    partial_sum(all(a), begin(a));
    dp.resize(n + 1, vector<i64>(n + 1, -1));
    cout << dfs(0, n) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
