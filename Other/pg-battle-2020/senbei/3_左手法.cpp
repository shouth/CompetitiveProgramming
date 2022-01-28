#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;


void solve() {
    i64 H, W;
    cin >> H >> W;
    i64 Px, Py, Qx, Qy;
    cin >> Px >> Py >> Qx >> Qy;
    Px--, Py--, Qx--, Qy--;

    vector<string> m(H);
    for (auto& row : m) cin >> row;

    i64 x = Px, y = Py;
    i64 ans = 0;
    i64 dir = 1; // 0: west, 1: north, 2: east, 3: south

    auto enter = [&](i64 nx, i64 ny) {
        if (nx < 0 || nx >= H) return false;
        if (ny < 0 || ny >= W) return false;
        if (m[nx][ny] == '#') return false;
        return true;
    };
    while (x != Qx || y != Qy) {
        i64 ndir = -1;
        for (i64 i = 0; i < 4; i++) {
            i64 nx, ny;
            ndir = (dir + i + 3) % 4;
            switch (ndir) {
            case 0: nx = x,     ny = y - 1; break;
            case 1: nx = x - 1, ny = y;     break;
            case 2: nx = x,     ny = y + 1; break;
            case 3: nx = x + 1, ny = y;     break;
            }

            if (enter(nx, ny)) {
                x = nx;
                y = ny;
                dir = ndir;
                ans++;
                break;
            }
        }

        if (ndir == -1) {
            ans = -1;
            break;
        }

        if (ans >= H * W * 4) {
            ans = -1;
            break;
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
