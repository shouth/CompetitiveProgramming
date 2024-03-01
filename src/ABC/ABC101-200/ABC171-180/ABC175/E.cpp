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
    i64 r, c, k;
    cin >> r >> c >> k;

    vector v(r, vector(c, 0l));
    for (i64 i = 0; i < k; i++) {
        i64 ri, ci, vi;
        cin >> ri >> ci >> vi, ri--, ci--;
        v[ri][ci] = vi;
    }

    vector dp(c, vector(4, -INF));
    dp[0][0] = 0;
    for (i64 x = 0; x < r; x++) {
        for (i64 y = 0; y < c; y++) {
            for (i64 z = 3; z > 0; z--) dp[y][z] = max(dp[y][z], dp[y][z - 1] + v[x][y]);
            if (y + 1 < c) for (i64 z = 0; z < 4; z++) dp[y + 1][z] = max(dp[y + 1][z], dp[y][z]);
            if (x + 1 < r) for (i64 z = 0; z < 4; z++) dp[y][0] = max(dp[y][0], dp[y][z]);
        }
    }

    cout << *max_element(all(dp[c - 1])) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
