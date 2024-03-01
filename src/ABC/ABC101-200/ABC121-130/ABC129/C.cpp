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

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> broken(n+1, false);
    for (int i=0; i<m; i++) {
        int a;
        cin >> a;
        broken[a] = true;
    }

    vector<int64_t> dp(n+1);
    dp[0] = 1, dp[1] = 1 - broken[1];
    for (int i=2; i<=n; i++) {
        if (broken[i]) continue;
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[n] << endl;
}
