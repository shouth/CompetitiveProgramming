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

void solve() {
    i64 n;
    cin >> n;

    vector<vector<i64>> dp(3, vector<i64>(n + 1));
    for (i64 i = 0; i < n; i++) {
        vector<i64> h(3);
        for (auto& e : h) cin >> e;
        for (i64 j = 0; j < 3; j++) {
            dp[j][i + 1] = max(dp[(j + 1) % 3][i] + h[(j + 1) % 3], dp[(j + 2) % 3][i] + h[(j + 2) % 3]);
        }
    }
    cout << max({ dp[0][n], dp[1][n], dp[2][n] }) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
