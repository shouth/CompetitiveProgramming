#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include <algorithm>
#include <atcoder/all>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

auto solve() -> void
{
    i64 H, W;
    cin >> H >> W;
    auto S = vector<string>(H);
    for (auto &row : S) cin >> row;

    auto punch = std::vector<p64> {
        /*       */ { -1, +2 }, {  0, +2 }, { +1, +2 }, /*       */
        { -2, +1 }, { -1, +1 }, {  0, +1 }, { +1, +1 }, { +2, +1 },
        { -2,  0 }, { -1,  0 }, /*       */ { +1,  0 }, { +2,  0 },
        { -2, -1 }, { -1, -1 }, {  0, -1 }, { +1, -1 }, { +2, -1 },
        /*       */ { -1, -2 }, {  0, -2 }, { +1, -2 }, /*       */
    };

    auto adjacent = std::vector<p64> {
        /*       */ {  0, +1 }, /*       */
        { -1,  0 }, /*       */ { +1,  0 },
        /*       */ {  0, -1 }, /*       */
    };

    auto dist = vector(H, vector<i64>(W, -1));
    auto q = deque<tuple<i64, i64, i64>>();
    q.emplace_back(0, 0, 0);
    while (not q.empty()) {
        auto [ y, x, w ] = q.front();
        q.pop_front();

        if (dist[y][x] != -1) continue;
        dist[y][x] = w;

        for (auto [ dy, dx ] : adjacent) {
            auto ny = y + dy;
            auto nx = x + dx;

            if (ny < 0 or ny >= H or nx < 0 or nx >= W or dist[ny][nx] != -1) continue;
            if (S[ny][nx] == '.') q.emplace_front(ny, nx, w);
        }

        for (auto [ dy, dx ] : punch) {
            auto ny = y + dy;
            auto nx = x + dx;

            if (ny < 0 or ny >= H or nx < 0 or nx >= W or dist[ny][nx] != -1) continue;
            q.emplace_back(ny, nx, w + 1);
        }
    }
    cout << dist[H - 1][W - 1] << endl;
}

auto main() -> int
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
