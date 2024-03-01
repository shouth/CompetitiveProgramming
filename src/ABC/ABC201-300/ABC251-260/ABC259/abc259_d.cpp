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

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

void solve() {
    i64 N;
    cin >> N;
    i64 sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    auto xyr = vector<tuple<i64, i64, i64>>(N);
    for (auto &[ x, y, r ] : xyr) {
        cin >> x >> y >> r;
    }

    auto graph = vector(N, vector<i64>());
    for (i64 i = 0; i < N; ++i) {
        for (i64 j = i + 1; j < N; ++j) {
            auto [ xi, yi, ri ] = xyr[i];
            auto [ xj, yj, rj ] = xyr[j];
            auto dx = xj - xi, dy = yj - yi;
            auto rl = ri - rj, rr = ri + rj;
            auto dist = dx * dx + dy * dy;
            if (rl * rl <= dist && dist <= rr * rr) {
                graph[i].emplace_back(j);
                graph[j].emplace_back(i);
            }
        }
    }

    auto grouped = vector<i64>(N, -1);
    auto q = queue<i64>();
    for (i64 i = 0; i < N; ++i) {
        if (grouped[i] != -1) continue;
        grouped[i] = i;
        q.emplace(i);

        while (not q.empty()) {
            i64 t = q.front();
            q.pop();

            for (auto e : graph[t]) {
                if (grouped[e] != -1) continue;
                grouped[e] = i;
                q.emplace(e);
            }
        }
    }

    for (i64 i = 0; i < N; ++i) {
        auto [ ssx, ssy, ssr ] = xyr[i];
        auto sdx = ssx - sx;
        auto sdy = ssy - sy;
        if (sdx * sdx + sdy * sdy != ssr * ssr) continue;

        for (i64 j = 0; j < N; ++j) {
            auto [ ttx, tty, ttr ] = xyr[j];
            auto tdx = ttx - tx;
            auto tdy = tty - ty;
            if (tdx * tdx + tdy * tdy != ttr * ttr) continue;

            if (grouped[i] == grouped[j]) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
