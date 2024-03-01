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

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n, k;
    cin >> n >> k;
    map<i64, i64> ab;
    for (i64 i = 0; i < n; i++) {
        i64 a, b;
        cin >> a >> b;
        ab[a] += b;
    }

    i64 ans = 0;
    for (auto& e : ab) {
        i64 a, b;
        tie(a, b) = e;
        if (!(a & ~k)) ans += b;
    }

    for (i64 i = 0; i < 30; i++) {
        if (!((k >> i) & 1)) continue;
        i64 can = 0;
        i64 l = (k & ~(1 << i)) | ((1 << i) - 1);
        for (auto& e : ab) {
            i64 a, b;
            tie(a, b) = e;
            if (!(a & ~l)) can += b;
        }
        ans = max(ans, can);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
