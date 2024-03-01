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

i64 n;
vector<vector<vector<f64>>> dp;

f64 dfs(i64 i, i64 j, i64 k) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (i == 0 && j == 0 && k == 0) return 0;
    if (dp[i][j][k] >= 0) return dp[i][j][k];

    f64 res = (f64) n;
    res += (f64) i * dfs(i - 1, j , k);
    res += (f64) j * dfs(i + 1, j - 1, k);
    res += (f64) k * dfs(i, j + 1, k - 1);
    res /= (f64) (i + j + k);
    return dp[i][j][k] = res;
}

void solve() {
    cin >> n;

    i64 cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        (a == 1 ? cnt1 : a == 2 ? cnt2 : cnt3)++;
    }

    dp.resize(n + 1, vector<vector<f64>>(n + 1, vector<f64>(n + 1, -1)));
    cout << dfs(cnt1, cnt2, cnt3) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
