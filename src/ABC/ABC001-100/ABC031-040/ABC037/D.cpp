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
    int64_t h, w;
    cin >> h >> w;
    vector<vector<int64_t>> a(h, vector<int64_t>(w));
    for (auto& e : a) for (auto& f : e) cin >> f;

    vector<vector<int64_t>> dp(h, vector<int64_t>(w, -1));
    vector<int64_t> dxy { 0, 1, 0, -1, 0 };

    auto f = [&](const auto g, const auto hi, const auto wi) {
        if (dp[hi][wi] != -1) return dp[hi][wi];

        int64_t res = 1;
        for (int64_t i = 0; i < 4; i++) {
            int64_t nhi = hi + dxy[i], nwi = wi + dxy[i+1];
            if (nhi < 0 || h <= nhi || nwi < 0 || w <= nwi) continue;
            if (a[hi][wi] >= a[nhi][nwi]) continue;
            res += g(g, nhi, nwi);
            res %= MOD;
        }
        return dp[hi][wi] = res;
    };

    int64_t ans = 0;
    for (int64_t i = 0; i < h; i++) {
        for (int64_t j = 0; j < w; j++) {
            ans += f(f, i, j);
            ans %= MOD;
        }
    }

    cout << ans << endl;
}
