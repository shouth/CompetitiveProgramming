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
    i64 n, w;
    cin >> n >> w;

    i64 m = n *  (i64) 1e3;
    vector<i64> dp(m + 1, INF);
    dp[0] = 0;

    for (i64 i = 0; i < n; i++) {
        i64 wi, vi;
        cin >> wi >> vi;

        for (i64 j = m; j >= vi; j--) {
            dp[j] = min(dp[j], dp[j - vi] + wi);
        }
    }

    for (i64 i = m; i >= 0; i--) {
        if (dp[i] <= w) {
            cout << i << endl;
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
