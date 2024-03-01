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

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<string> ss(n);
    vector<i64> ls(n, -INF), rs(n, -INF);
    vector<i64> pos, neg;
    for (i64 i = 0; i < n; i++) {
        cin >> ss[i];
        i64 m = ss[i].size();

        for (i64 j = 0, lc = 0; j < m; j++) {
            if (ss[i][j] == ')') lc++; else lc--;
            ls[i] = max(ls[i], lc);
        }
        for (i64 j = m - 1, rc = 0; j >= 0; j--) {
            if (ss[i][j] == '(') rc++; else rc--;
            rs[i] = max(rs[i], rc);
        }

        (rs[i] - ls[i] >= 0 ? pos : neg).emplace_back(i);
    }

    sort(begin(pos), end(pos), [&](i64 x, i64 y) { return ls[x] < ls[y]; });
    sort(begin(neg), end(neg), [&](i64 x, i64 y) { return rs[x] > rs[y]; });

    string str;
    for (auto& e : pos) str.append(ss[e]);
    for (auto& e : neg) str.append(ss[e]);

    i64 cnt = 0;
    for (auto& e : str) {
        if (e == '(') cnt++; else cnt--;
        if (cnt < 0) break;
    }

    cout << (cnt != 0 ? "No" : "Yes") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
