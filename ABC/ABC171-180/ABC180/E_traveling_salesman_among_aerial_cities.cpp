#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct pos {
    i64 x, y, z;
};

i64 N;
vector<vector<i64>> dp;
vector<pos> cities(N);

i64 distance(i64 from, i64 to) {
    auto [ a, b, c ] = cities[from];
    auto [ p, q, r ] = cities[to];
    return abs(p - a) + abs(q - b) + max(0l, r - c);
}

i64 dfs(i64 visited, i64 last) {
    if (dp[visited][last] != -1) return dp[visited][last];
    if (visited == (1l << N) - 1) return distance(last, 0);

    i64 res = INF;
    for (i64 i = 0; i < N; i++) {
        if ((visited >> i) & 1) continue;
        res = min(res, distance(last, i) + dfs(visited | (1l << i), i));
    }
    return dp[visited][last] = res;
}

void solve() {
    cin >> N;
    dp.resize(1l << N, vector<i64>(N, -1));
    cities.resize(N);
    for (auto& [ x, y, z ] : cities) cin >> x >> y >> z;
    cout << dfs(1, 0) << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
