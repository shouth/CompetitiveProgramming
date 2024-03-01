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
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> f(n);
    for (auto& e : f) cin >> e, e--;

    vector<int64_t> use(m);
    vector<int64_t> dp(n+1);
    dp[0] = 1;
    int64_t t = 0;
    for (int64_t l = 0, r = 0; r < n; r++) {
        t = (t + dp[r]) % MOD;
        use[f[r]]++;
        while (use[f[r]] > 1) {
            use[f[l]]--;
            t = (t - dp[l] + MOD) % MOD;
            l++;
        }
        dp[r+1] = t;
    }

    cout << dp[n] << endl;
}
