#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

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
#include <atcoder/all>

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
    i64 h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    auto f = [](i64 x) {
        auto res = vector<array<i64, 3>>();
        for (i64 a = 1; a < x; ++a) {
            for (i64 b = 1; a + b < x; ++b) {
                res.push_back({ a, b, x - a - b });
            }
        }
        return res;
    };

    auto ts1 = f(h1);
    auto ts2 = f(h2);
    i64 ans = 0;
    for (const auto [ a1, a2, a3 ] : ts1) {
        for (const auto [ b1, b2, b3 ] : ts2) {
            i64 s1 = w1 - a1 - b1;
            i64 s2 = w2 - a2 - b2;
            i64 s3 = w3 - a3 - b3;
            ans += s1 > 0 && s2 > 0 && s3 > 0 && s1 + s2 + s3 == h3;
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
