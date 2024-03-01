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

constexpr int MOD = 1e9 + 7;

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<int>> r {{0}};
    for (int n = 1; n < w; n++) {
        vector<vector<int>> s;
        for (auto e : r) {
            auto f = e;
            f.push_back(n);
            s.push_back(f);
            if (f[n-1] == n-1) {
                swap(f[n-1], f[n]);
                s.push_back(f);
            }
        }
        r = s;
    }

    vector<vector<int>> dp(h+1, vector<int>(w));
    dp[0][0] = 1;
    for (int i = 0; i + 1 <= h; i++) {
        for (auto& e : r) {
            for (int n = 0; n < w; n++) {
                dp[i+1][e[n]] += dp[i][n];
                dp[i+1][e[n]] %= MOD;
            }
        }
    }

    cout << dp[h][k-1] << endl;
}
