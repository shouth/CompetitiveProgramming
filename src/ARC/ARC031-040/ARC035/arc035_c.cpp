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
    vector<vector<i64>> g(n, vector<i64>(n, INF));
    for (i64 i = 0; i < n; i++) g[i][i] = 0;
    for (i64 i = 0; i < m; i++) {
        i64 a, b, c;
        cin >> a >> b >> c, a--, b--;
        g[a][b] = g[b][a] = c;
    }

    for (i64 i = 0; i < n; i++) {
        for (i64 j = 0; j < n; j++) {
            for (i64 k = 0; k < n; k++) {
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
            }
        }
    }

    i64 kk;
    cin >> kk;
    for (i64 i = 0; i < kk; i++) {
        i64 x, y, z;
        cin >> x >> y >> z, x--, y--;

        if (z < g[x][y]) {
            g[x][y] = g[y][x] = z;
            for (i64 j = 0; j < n; j++) {
                for (i64 k = 0; k < n; k++) {
                    g[j][k] = min({ g[j][k], g[j][x] + g[x][y] + g[y][k], g[j][y] + g[y][x] + g[x][k] });
                }
            }
        }

        i64 s = 0;
        for (i64 j = 0; j < n; j++) {
            for (i64 k = j + 1; k < n; k++) {
                s += g[j][k];
            }
        }
        cout << s << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
