#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

void solve()
{
    i64 H, W, C;
    cin >> H >> W >> C;

    auto A = vector(H, vector<i64>(W));
    for (auto &row : A) {
        for (auto &e : row) {
            cin >> e;
        }
    }

    auto X = vector(H, vector<i64>(W));
    auto calc = [&]() -> i64 {
        i64 res = INF;
        for (i64 h = 0; h < H; ++h) {
            for (i64 w = 0; w < W; ++w) {
                X[h][w] = A[h][w] - C * (h + w);
                if (h - 1 >= 0) {
                    X[h][w] = min(X[h][w], X[h - 1][w]);
                    res = min(res, X[h - 1][w] + A[h][w] + C * (h + w));
                }
                if (w - 1 >= 0) {
                    X[h][w] = min(X[h][w], X[h][w - 1]);
                    res = min(res, X[h][w - 1] + A[h][w] + C * (h + w));
                }
            }
        }
        return res;
    };

    i64 ans0 = calc();
    for (auto &e : A) reverse(e.begin(), e.end());
    for (auto &e : X) e.assign(W, 0);
    i64 ans1 = calc();
    cout << min(ans0, ans1) << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
