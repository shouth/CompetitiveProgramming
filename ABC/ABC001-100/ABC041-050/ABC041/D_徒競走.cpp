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
    int64_t n, m;
    cin >> n >> m;

    vector<bitset<16>> adj(n);
    for (int64_t i = 0; i < m; i++) {
        int64_t x, y;
        cin >> x >> y, x--, y--;
        adj[x][y] = 1;
    }

    vector<int64_t> dp(1 << n);
    dp[0] = 1;
    for (int64_t i = 0; i < (1 << n); i++) {
        for (int64_t j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;

            bool integrity = true;
            for (int64_t k = 0; k < n; k++) {
                if (((i >> k) & 1) && adj[j][k]) integrity = false;
            }

            if (integrity) dp[i + (1 << j)] += dp[i];
        }
    }

    cout << dp.back() << endl;
}
