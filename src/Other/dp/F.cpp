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
    string s, t;
    cin >> s >> t;
    i64 n = s.size(), m = t.size();

    vector<vector<i64>> dp(n + 1, vector<i64>(m + 1));
    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < m; j++) {
            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    string ans;
    i64 i = n, j = m;
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } else {
            i--, j--;
            ans.push_back(s[i]);
        }
    }
    reverse(all(ans));
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
