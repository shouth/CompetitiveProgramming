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
    i64 n, m;
    cin >> n >> m;
    vector<vector<i64>> path(n);
    for (i64 i = 0; i < m; i++) {
        i64 a, b;
        cin >> a >> b, a--, b--;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }

    vector<i64> to(n, -1);
    queue<i64> from; // 1: node
    from.emplace(0);
    while (!from.empty()) {
        i64 node = from.front(); from.pop();

        for (auto& nxt : path[node]) {
            if (to[nxt] != -1) continue;
            to[nxt] = node;
            from.push(nxt);
        }
    }

    for (i64 i = 1; i < n; i++) {
        if (to[i] == -1) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
    for (i64 i = 1; i < n; i++) {
        cout << to[i] + 1 << endl;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
