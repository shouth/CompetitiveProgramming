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
    i64 k;
    cin >> k;

    vector<i64> v;
    i64 suc = 1;
    s.push_back('.');
    for (i64 i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            suc++;
        } else {
            v.emplace_back(suc);
            suc = 1;
        }
    }
    s.pop_back();

    if (v.size() == 1) {
        cout << n * k / 2 << endl;
        return;
    }

    i64 ans = 0;
    for (i64 i = 1; i < (i64) v.size() - 1; i++) ans += v[i] / 2 * k;
    if (s.front() == s.back()) {
        ans += (v.front() + v.back()) / 2 * (k - 1);
        ans += v.front() / 2 + v.back() / 2;
    } else {
        ans += (v.front() / 2 + v.back() / 2) * k;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
