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
    i64 n, m, q;
    cin >> n >> m >> q;

    vector<i64> score(m, n);
    vector<vector<i64>> solved(n);
    for (i64 i = 0; i < q; i++) {
        i64 c;
        cin >> c;
        if (c == 1) {
            i64 nn;
            cin >> nn, nn--;
            i64 ans = 0;
            for (auto& e : solved[nn]) ans += score[e];
            cout << ans << endl;
        } else {
            i64 nn, mm;
            cin >> nn >> mm, nn--, mm--;
            solved[nn].emplace_back(mm);
            score[mm]--;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
