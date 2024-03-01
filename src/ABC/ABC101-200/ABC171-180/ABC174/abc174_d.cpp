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
    i64 n;
    cin >> n;

    vector<i64> rcnt(n + 1);
    for (i64 i = 0; i < n; i++) {
        char c;
        cin >> c;
        rcnt[i + 1] = c == 'R';
    }
    partial_sum(all(rcnt), begin(rcnt));

    i64 ans = INF;
    for (i64 i = 0; i <= n; i++) {
        ans = min(ans, max(i - (rcnt[i] - rcnt[0]), rcnt[n] - rcnt[i]));
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
