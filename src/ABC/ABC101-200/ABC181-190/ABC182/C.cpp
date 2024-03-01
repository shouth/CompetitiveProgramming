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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    i64 d = (i64) log10(N) + 1;
    i64 ans = INF;
    for (i64 i = 1; i < (1l << d); i++) {
        i64 sum = 0;
        i64 tmp = N;
        for (i64 j = 0; j < d; j++) {
            if ((i >> j) & 1) sum += tmp % 10;
            tmp /= 10;
        }
        if (sum % 3 == 0) ans = min(ans, d - (i64) __builtin_popcountl(i));
    }
    cout << (ans == INF ? -1 : ans) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
