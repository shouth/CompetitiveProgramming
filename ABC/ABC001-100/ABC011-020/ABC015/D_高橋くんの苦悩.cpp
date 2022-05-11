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
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<vector<int>> dp(k+1, vector<int>(w+1));
    for (int x = 0; x < n; x++) {
        for (int y = k; y > 0; y--) {
            for (int z = w; z >= a[x]; z--) {
                dp[y][z] = max(dp[y][z], dp[y-1][z-a[x]] + b[x]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= w; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
