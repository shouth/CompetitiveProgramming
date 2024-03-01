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
    i64 n, m;
    cin >> n >> m;
    vector<p64> order(n);
    for (i64 i = 0; i < n; i++) {
        order[i] = { INF, i };
    }
    for (i64 i = 0; i < m; i++) {
        i64 a;
        cin >> a, a--;
        order[a].first = m - i;
    }
    sort(all(order));
    for (auto& e : order) cout << e.second + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
