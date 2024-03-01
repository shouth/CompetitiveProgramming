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

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> b(n, vector<i64>(m));
    for (auto& e : b) for (auto& f : e) cin >> (char&) f, f -= '0';

    vector<vector<i64>> ans(n, vector<i64>(m));
    for (i64 i = 1; i < n - 1; i++) {
        for (i64 j = 1; j < m - 1; j++) {
            ans[i][j] = b[i - 1][j];
            b[i][j - 1] -= ans[i][j];
            b[i][j + 1] -= ans[i][j];
            b[i + 1][j] -= ans[i][j];
        }
    }

    for (auto& e : ans) {
        for (auto& f : e) {
            cout << f;
        }
        cout << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
