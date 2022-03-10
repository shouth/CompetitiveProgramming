#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    vector<p64> points(N);
    for (auto& [ x, y ] : points) cin >> x >> y;

    i64 ans = 0;
    for (i64 i = 0; i < N; i++) {
        for (i64 j = i + 1; j < N; j++) {
            auto [ xs, ys ] = points[i];
            auto [ xg, yg ] = points[j];
            i64 dx = xg - xs, dy = yg - ys;
            if (dx < 0) dx *= -1, dy *= -1;
            if (dy >= -dx && dy <= dx) ans++;
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