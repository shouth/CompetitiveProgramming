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
    i64 x;
    cin >> x;
    i64 m = 100;
    i64 ans = 0;
    while (m < x) {
        m *= 1.01, ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
