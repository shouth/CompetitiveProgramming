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
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, l;
    cin >> n >> l;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;

    i64 idx = adjacent_find(all(a), [&](i64 x, i64 y) { return x + y >= l; }) - begin(a);
    if (idx == n) {
        cout << "Impossible" << endl;
        return;
    }

    cout << "Possible" << endl;
    for (i64 i = 0; i < idx; i++) cout << i + 1 << endl;
    for (i64 i = n - 2; i > idx; i--) cout << i + 1 << endl;
    cout << idx + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
