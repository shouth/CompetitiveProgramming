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
    i64 n;
    cin >> n;

    i64 ans = 0;
    for (i64 i = 1; (f64) i <= sqrt(n); i++) {
        if (n % i != 0) continue;
        if ((i - 1) != 0 && n % (i - 1) == n / (i - 1)) ans += i - 1;
        if (i == n / i) continue;
        if ((n / i - 1) != 0 && n % (n / i - 1) == n / (n / i - 1)) ans += n / i - 1;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
