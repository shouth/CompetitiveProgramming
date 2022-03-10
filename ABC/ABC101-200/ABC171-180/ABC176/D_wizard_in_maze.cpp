#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 H, W;
    cin >> H >> W;
    i64 Ch, Cw;
    cin >> Ch >> Cw, Ch--, Cw--;
    i64 Dh, Dw;
    cin >> Dh >> Dw, Dh--, Dw--;

    auto S = vector<string>(H);
    for (auto& e : S) cin >> e;

    auto dist = vector(H, vector(W, INF));
    dist[Ch][Cw] = 0;
    auto d = deque<p64>();
    d.emplace_back(Ch, Cw);
    vector<i64> dxy { 0, 1, 0, -1, 0 };
    while (!d.empty()) {
        auto [ y, x ] = d.front(); d.pop_front();
        for (i64 i = 0; i < 4; i++) {
            i64 ny = y + dxy[i], nx = x + dxy[i + 1];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#') continue;
            if (dist[ny][nx] <= dist[y][x]) continue;
            dist[ny][nx] = dist[y][x];
            d.emplace_front(ny, nx);
        }

        for (i64 i = -2; i <= 2; i++) {
            for (i64 j = -2; j <= 2; j++) {
                i64 ny = y + i, nx = x + j;
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (S[ny][nx] == '#') continue;
                if (dist[ny][nx] <= dist[y][x] + 1) continue;
                dist[ny][nx] = dist[y][x] + 1;
                d.emplace_back(ny, nx);
            }
        }
    }
    cout << (dist[Dh][Dw] != INF ? dist[Dh][Dw] : -1) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
