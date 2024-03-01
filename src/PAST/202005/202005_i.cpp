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
    i64 n, q;
    cin >> n >> q;

    vector<i64> row(n), col(n);
    iota(all(row), 0);
    iota(all(col), 0);

    bool trans = false;
    for (i64 i = 0; i < q; i++) {
        i64 c;
        cin >> c;

        i64 a, b;
        switch (c) {
        case 1:
            cin >> a >> b, a--, b--;
            trans ? swap(col[a], col[b]) : swap(row[a], row[b]);
            break;
        case 2:
            cin >> a >> b, a--, b--;
            trans ? swap(row[a], row[b]) : swap(col[a], col[b]);
            break;
        case 3:
            trans = !trans;
            break;
        case 4:
            cin >> a >> b, a--, b--;
            cout << (trans ? n * row[b] + col[a] : n * row[a] + col[b]) << endl;
            break;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
