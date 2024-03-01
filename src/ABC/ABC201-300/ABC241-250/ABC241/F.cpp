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
    i64 H, W, N;
    cin >> H >> W >> N;
    i64 sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    auto Xss = map<i64, vector<i64>>();
    auto Yss = map<i64, vector<i64>>();
    for (i64 i = 0; i < N; i++) {
        i64 X, Y;
        cin >> X >> Y;
        Xss[Y].emplace_back(X);
        Yss[X].emplace_back(Y);
    }

    for (auto &[ _, v ] : Xss) sort(all(v));
    for (auto &[ _, v ] : Yss) sort(all(v));

    auto dist = map<p64, i64>();
    auto q = queue<p64>();
    q.emplace(sx, sy);
    dist[{ sx, sy }] = 0;
    while (!q.empty()) {
        auto [ x, y ] = q.front();
        q.pop();

        auto push = [&, x = x, y = y](i64 nx, i64 ny) {
            if (dist.count({ nx, ny })) return;
            dist[{ nx, ny }] = dist[{ x, y }] + 1;
            q.emplace(nx, ny);
        };

        if (Xss.count(y)) {
            const auto &Xs = Xss[y];
            auto itr = upper_bound(all(Xs), x);
            if (itr != Xs.end()) push(itr[0] - 1, y);
            if (itr != Xs.begin()) push(itr[-1] + 1, y);
        }

        if (Yss.count(x)) {
            const auto &Ys = Yss[x];
            auto itr = upper_bound(all(Ys), y);
            if (itr != Ys.end()) push(x, itr[0] - 1);
            if (itr != Ys.begin()) push(x, itr[-1] + 1);
        }
    }
    cout << (dist.count({ gx, gy }) ? dist[{ gx, gy }] : -1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
