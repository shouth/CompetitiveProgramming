#include<bits/stdc++.h>
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
    i64 N;
    cin >> N;
    i64 Ax, Ay;
    cin >> Ax >> Ay, Ax--, Ay--;
    i64 Bx, By;
    cin >> Bx >> By, Bx--, By--;

    auto dist = vector(N, vector(N, i64(-1)));
    for (auto &e : dist) {
        string s;
        cin >> s;
        for (i64 i = 0; i < N; i++) {
            if (s[i] == '#') e[i] = INF;
        }
    }

    auto q = queue<p64>();
    q.emplace(Ax, Ay);
    dist[Ax][Ay] = 0;
    while (!q.empty()) {
        auto [ x, y ] = q.front();
        q.pop();

        auto dxy = vector<i64> { 1, 1, -1, -1, 1 };
        for (i64 i = 0; i < 4; i++) {
            i64 dx = dxy[i], dy = dxy[i + 1];
            i64 nx = x, ny = y;
            while (true) {
                nx += dx, ny += dy;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
                if (dist[nx][ny] != dist[x][y] + 1) break;
            }
        }
    }
    cout << dist[Bx][By] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
