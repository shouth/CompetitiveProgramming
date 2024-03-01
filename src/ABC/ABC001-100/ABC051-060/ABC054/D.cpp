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
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(401, vector<int>(401, 1e9)));
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 400; j++) {
            for (int k = 0; k <= 400; k++) {
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                if (j+a[i] <= 400 && k+b[i] <= 400) dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k]+c[i]);
            }
        }
    }

    int ans = 1e9;
    for (int ia = ma, ib = mb; ia <= 400 && ib <= 400; ia += ma, ib += mb) {
        ans = min(ans, dp[n][ia][ib]);
    }
    cout << (ans != 1e9 ? ans : -1) << endl;
}
