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
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> h(n);
    for (auto& e : h) cin >> e;
    i64 b, e;
    for (b = 0; b + 1 < n && h[b] > h[b + 1]; b++);
    for (e = n - 1; e - 1 >= 0 && h[e - 1] < h[e]; e--);
    i64 ans = max(b + 1, n - e);
    i64 l = 0;
    for (i64 i = b; i <= e; i++) {
        if (i - 1 < 0) continue;
        if (i + 1 >= n || (h[i - 1] > h[i] && h[i] < h[i + 1])) {
            ans = max(ans, i - l + 1);
            l = i;
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
