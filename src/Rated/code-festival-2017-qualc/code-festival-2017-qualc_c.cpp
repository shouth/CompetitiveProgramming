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
    i64 l = 0, r = n - 1;
    i64 ans = 0;
    while (l < r) {
        if (s[l] == s[r]) {
            l++, r--;
            continue;
        }

        if (s[l] != 'x' && s[r] != 'x') {
            cout << -1 << endl;
            return;
        }

        ans++;
        if (s[l] == 'x') l++; else r--;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
