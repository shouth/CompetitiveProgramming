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
    i64 n, l;
    cin >> n >> l;
    vector<i64> x(n), d(n);
    for (i64 i = 0; i < n; i++) cin >> x[i] >> (char&) d[i];

    i64 ans = 0, i;
    for (i = 0; i < n && d[i] == 'L'; i++) ans += x[i] - (i + 1);
    i64 rb = i, re, lb, le;
    for (; i < n; i++) {
        if (i < n - 1 && d[i] == 'R' && d[i + 1] == 'L') {
            re = i, lb = i + 1;
        }
        if (d[i] == 'L' && (i == n - 1 || d[i + 1] == 'R')) {
            le = i;
            for (i64 j = re; j > rb; j--) {
                ans += x[j] - x[j - 1] - 1;
                x[j - 1] = x[j] - 1;
            }
            for (i64 j = lb; j < le; j++) {
                ans += x[j + 1] - x[j] - 1;
                x[j + 1] = x[j] + 1;
            }
            ans += (x[lb] - x[re] - 1) * max(re - rb + 1, le - lb + 1);
            rb = i + 1;
        }
    }
    for (i = n - 1; i >= 0 && d[i] == 'R'; i--) ans += l - x[i] - (n - 1 - i);
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
