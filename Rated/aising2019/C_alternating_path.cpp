#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto& e : s) cin >> e;

    i64 ans = 0;
    vector<i64> dxy { 0, 1, 0, -1, 0 };
    for (i64 i = 0; i < h; i++) {
        for (i64 j = 0; j < w; j++) {
            if (s[i][j] == '_') continue;

            queue<p64> q;
            q.emplace(i, j);
            i64 bcnt = 0, wcnt = 0;
            while (!q.empty()) {
                auto [ y, x ] = q.front(); q.pop();
                if (s[y][x] == '_') continue;
                (s[y][x] == '#' ? bcnt : wcnt)++;
                
                for (i64 k = 0; k < 4; k++) {
                    i64 ny = y + dxy[k], nx = x + dxy[k + 1];
                    if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
                    if (s[ny][nx] == '_' || s[y][x] == s[ny][nx]) continue;
                    q.emplace(ny, nx);
                }
                s[y][x] = '_';
            }
            ans += bcnt * wcnt;
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
