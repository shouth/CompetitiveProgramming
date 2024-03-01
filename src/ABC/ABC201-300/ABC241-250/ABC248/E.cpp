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

#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, K;
    cin >> N >> K;
    auto XY = vector<p64>(N);
    for (auto &[ X, Y ] : XY) cin >> X >> Y;

    if (K == 1) {
        cout << "Infinity" << endl;
        return;
    }

    sort(all(XY));
    auto vote = map<array<i64, 3>, i64>();
    for (i64 i = 0; i < N; i++) {
        auto [ x0, y0 ] = XY[i];
        for (i64 j = i + 1; j < N; j++) {
            auto [ x1, y1 ] = XY[j];
            i64 a = x1 - x0;
            i64 b = y0 - y1;
            i64 c = x0 * y1 - x1 * y0;
            i64 d = gcd(gcd(a, b), c);
            a /= d, b /= d, c /= d;
            vote[{ a, b, c }]++;
        }
    }

    i64 ans = 0;
    for (auto [ _, v ] : vote) {
        if (v >= K * (K - 1) / 2) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
