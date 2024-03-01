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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

auto e = vector(100, vector(100, vector(100, -1.0)));

f64 f(i64 a, i64 b, i64 c) {
    if (a == 100 || b == 100 || c == 100) return 0;
    if (e[a][b][c] >= 0) return e[a][b][c];
    f64 t = a + b + c;
    return e[a][b][c] = (f(a + 1, b, c) * a + f(a, b + 1, c) * b + f(a, b, c + 1) * c) / t + 1;
}

void solve() {
    i64 A, B, C;
    cin >> A >> B >> C;
    cout << f(A, B, C) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
