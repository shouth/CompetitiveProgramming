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

void solve() {
    i64 H, W;
    cin >> H >> W;

    auto m = vector(H, string());
    for (auto& e : m) cin >> e;

    i64 sx, sy, gx, gy;
    auto teleport = map<char, vector<p64>>();
    for (i64 i = 0; i < H; i++) {
        for (i64 j = 0; j < W; j++) {
            if (islower(m[i][j])) teleport[m[i][j]].emplace_back(i, j);
            if (m[i][j] == 'S') sy = i, sx = j;
            if (m[i][j] == 'G') gy = i, gx = j;
        }
    }

    auto dist = vector(H, vector(W, i64(-1)));
    dist[sy][sx] = 0;
    auto q = queue<p64>();
    q.emplace(sy, sx);
    auto dxy = vector { 0, 1, 0, -1, 0 };
    auto used = map<char, bool>();
    while (!q.empty()) {
        auto [ y, x ] = q.front();
        q.pop();

        for (i64 i = 0; i < 4; i++) {
            i64 ny = y + dxy[i], nx = x + dxy[i + 1];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (m[ny][nx] == '#') continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.emplace(ny, nx);
        }

        if (!islower(m[y][x])) continue;
        if (used[m[y][x]]) continue;
        used[m[y][x]] = true;
        for (auto& [ ny, nx ] : teleport[m[y][x]]) {
            if (ny == y && nx == x) continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.emplace(ny, nx);
        }
    }

    cout << dist[gy][gx] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
