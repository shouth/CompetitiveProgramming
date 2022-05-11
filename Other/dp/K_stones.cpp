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
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    vector<i64> dp(k + 1);
    for (i64 i = 0; i <= k; i++) {
        for (auto& e : a) {
            if (i >= e) dp[i] |= !dp[i - e];
        }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
