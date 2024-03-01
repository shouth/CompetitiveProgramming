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
    map<i64, i64> cnt;
    i64 amax = 0, amin = INF;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        cnt[a]++;
        amax = max(a, amax);
        amin = min(a, amin);
    }

    if (amin != (amax + 1) / 2) {
        cout << "Impossible" << endl;
        return;
    }

    if (cnt[amin] != (amax % 2 ? 2 : 1)) {
        cout << "Impossible" << endl;
        return;
    }

    for (i64 ai = amin + 1; ai <= amax; ai++) {
        if (cnt[ai] < 2) {
            cout << "Impossible" << endl;
            return;
        }
    }
    cout << "Possible" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
