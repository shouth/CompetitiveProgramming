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
    i64 N;
    cin >> N;

    auto empty = p64 { 1e9 + 1, -1e9 + 1 };
    auto balls = vector<p64>(N, empty);
    for (i64 i = 0; i < N; i++) {
        i64 X, C;
        cin >> X >> C, C--;
        auto &[ minx, maxx ] = balls[C];
        minx = min(minx, X), maxx = max(maxx, X);
    }

    balls.erase(remove(all(balls), empty), balls.end());
    balls.emplace_back(0, 0);
    auto dp = vector<p64>(2);
    for (const auto &[ minx, maxx ] : balls) {
        auto [ lcost, lpos ] = dp[0];
        auto [ rcost, rpos ] = dp[1];
        i64 cost = maxx - minx;
        dp[0] = { min(lcost + abs(lpos - minx), rcost + abs(rpos - minx)) + cost, maxx };
        dp[1] = { min(lcost + abs(lpos - maxx), rcost + abs(rpos - maxx)) + cost, minx };
    }
    cout << dp.front().first << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
