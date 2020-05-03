#include<bits/stdc++.h>
using namespace std;

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 h, w;
    cin >> h >> w;

    vector<vector<i64>> m(h, vector<i64>(w, -1));
    queue<p64> q;
    for (i64 i = 0; i < h; i++) {
        for (i64 j = 0; j < w; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                m[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    i64 ans = 0;
    vector<i64> dxy { 0, 1, 0, -1, 0 };
    while (!q.empty()) {
        i64 y, x;
        tie(y, x) = q.front(); q.pop();

        for (i64 i = 0; i < 4; i++) {
            i64 ny = y + dxy[i], nx = x + dxy[i + 1];
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (m[ny][nx] != -1) continue;
            m[ny][nx] = m[y][x] + 1;
            ans = max(ans, m[ny][nx]);
            q.emplace(ny, nx);
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
