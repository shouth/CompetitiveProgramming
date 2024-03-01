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
    string s;
    cin >> s;
    i64 n = s.size();
    s = '.' + s;

    i64 ans = 0;
    i64 a = 0, bc = 0;
    for (i64 i = n; i > 0;) {
        if (s[i] == 'A') {
            a++, i--, ans += bc;
            continue;
        }

        if (s[i - 1] == 'B' && s[i] == 'C') {
            bc++, i -= 2;
            continue;
        }

        a = 0, bc = 0, i--;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
