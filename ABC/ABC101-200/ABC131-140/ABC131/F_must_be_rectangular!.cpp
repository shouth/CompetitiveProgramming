#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    vector<vector<i64>> g(2e5);
    vector<bool> valid(2e5);
    for (i64 i = 0; i < N; i++) {
        i64 x, y;
        cin >> x >> y, x--, y--;
        y += (i64) 1e5;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
        valid[x] = valid[y] = true;
    }

    i64 ans = 0;
    for (i64 i = 0; i < (i64) 1e5; i++) {
        if (!valid[i]) continue;
        valid[i] = false;

        i64 xcnt = 0, ycnt = 0, edge = 0;
        queue<i64> q;
        q.emplace(i);
        while (!q.empty()) {
            i64 t = q.front();
            q.pop();

            (t < (i64) 1e5 ? xcnt : ycnt)++;
            edge += g[t].size();

            for (auto& e : g[t]) {
                if (!valid[e]) continue;
                valid[e] = false;
                q.emplace(e);
            }
        }
        ans += xcnt * ycnt - edge / 2;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
