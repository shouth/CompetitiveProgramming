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
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    string s;
    cin >> s;
    i64 n = s.size();

    if (s.size() < 26) {
        for (char c = 'a'; c <= 'z'; c++) {
            if (s.find(c) == string::npos) {
                cout << s + c << endl;
                return;
            }
        }
    } else {
        for (i64 i = n - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                cout << s.substr(0, i) + *lower_bound(rbegin(s), rbegin(s) + n - i, s[i]) << endl;
                return;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
