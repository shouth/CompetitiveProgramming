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

int main() {
    int64_t n, a;
    cin >> n >> a;
    vector<int64_t> x(n);
    for (auto& e : x) cin >> e;

    vector<vector<vector<int64_t>>> dp(n+1, vector<vector<int64_t>>(n*a+1, vector<int64_t>(n+1)));
    dp[0][0][0] = 1;
    for (int64_t i = 0; i < n; i++) {
        for (int64_t s = 0; s <= n*a; s++) {
            for (int64_t j = 0; j <= n; j++) {
                dp[i+1][s][j] += dp[i][s][j];
                if (s+x[i] <= n*a) dp[i+1][s+x[i]][j+1] += dp[i][s][j];
            }
        }
    }

    int64_t ans = 0;
    for (int64_t j = 1; j <= n; j++) ans += dp[n][j*a][j];
    cout << ans << endl;
}
