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
    i64 l = (i64) sqrt(n);
    vector<i64> ans(n + 1);
    for (i64 x = 1; x <= l; x++) {
        for (i64 y = 1; y <= l; y++) {
            for (i64 z = 1; z <= l; z++) {
                i64 t = x * x + y * y + z * z + x * y + y * z + z * x;
                if (t <= n) ans[t]++;
            }
        }
    }
    for (i64 i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
