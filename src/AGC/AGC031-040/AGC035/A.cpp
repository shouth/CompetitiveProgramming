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
    map<i64, i64> m;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        m[a]++;
    }

    string ans = "No";

    switch (m.size()) {
    case 1:
        if (m[0] == n) ans = "Yes";
        break;

    case 2:
        i64 key;
        for (auto& e : m) if (e.first != 0) key = e.first;
        if (m[0] == n / 3 && m[key] == 2 * n / 3) ans = "Yes";
        break;

    case 3:
        i64 flag0 = 0, flag1 = 0;
        for (auto& e : m) {
            flag0 ^= e.first;
            flag1 |= e.second != n / 3;
        }
        if (!flag0 && !flag1) ans = "Yes";
        break;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
