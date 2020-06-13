#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 base = 300;
    i64 n, x, y;
    cin >> n >> x >> y, x += base, y += base;
    vector<vector<i64>> dist(base * 2, vector<i64>(base * 2, -1));
    dist[base][base] = 0;
    for (i64 i = 0; i < n; i++) {
        i64 xi, yi;
        cin >> xi >> yi, xi += base, yi += base;
        dist[xi][yi] = INF;
    }

    queue<p64> q;
    q.emplace(base, base);
    vector<p64> dxy { { 1, 1 }, { 0, 1 }, { -1, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };
    while (!q.empty()) {
        auto [ cx, cy ] = q.front(); q.pop();
        for (auto& [ dx, dy ] : dxy) {
            i64 nx = cx + dx, ny = cy + dy;
            if (nx < 0 || nx >= 2 * base || ny < 0 || ny >= 2 * base) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[cx][cy] + 1;
            q.emplace(nx, ny);
        }
    }

    cout << dist[x][y] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
