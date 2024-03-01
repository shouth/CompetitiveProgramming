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

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 n, m, v, p;
    cin >> n >> m >> v >> p;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    sort(begin(a), end(a), greater<>());

    i64 l = 0, r = n;
    while (abs(r - l) > 1) {
        i64 mid = (l + r) / 2;

        if (mid < p) {
            l = mid;
            continue;
        }

        if (a[p - 1] > a[mid] + m) {
            r = mid;
            continue;
        }

        i64 sum = 0;
        for (i64 i = 0; i < n; i++) {
            sum += i < p - 1 || i >= mid ? m : a[mid] + m - a[i];
        }

        (sum >= m * v ? l : r) = mid;
    }

    cout << l + 1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
