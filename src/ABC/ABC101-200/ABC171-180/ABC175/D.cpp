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
    i64 n, k;
    cin >> n >> k;
    vector<i64> p(n), c(n);
    for (auto& e : p) cin >> e, e--;
    for (auto& e : c) cin >> e;

    vector<i64> used(n);
    vector<vector<i64>> loops;
    for (i64 i = 0; i < n; i++) {
        if (used[i]) continue;
        vector<i64> loop;
        for (i64 j = i; !used[j]; j = p[j]) {
            loop.emplace_back(c[j]);
            used[j] = 1;
        }
        loops.emplace_back(loop);
    }

    i64 ans = -INF;
    for (auto& loop : loops) {
        i64 m = loop.size();

        vector<i64> sum(2 * m + 1);
        for (i64 i = 0; i < 2 * m; i++) sum[i + 1] = sum[i] + loop[i % m];

        vector<i64> rem(m, -INF);
        for (i64 i = 0; i < m; i++) {
            for (i64 j = 0; j < m; j++) {
                rem[j] = max(rem[j], sum[i + j] - sum[i]);
            }
        }

        for (i64 i = 0; i < m; i++) {
            if (i > k) continue;
            i64 q = (k - i) / m;
            if (i == 0 && q == 0) continue;
            if (sum[m] > 0) ans = max(ans, rem[i] + sum[m] * q);
            else if (i > 0) ans = max(ans, rem[i]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
