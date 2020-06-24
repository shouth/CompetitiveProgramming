#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    map<i64, map<i64, vector<i64>>> g;
    for (i64 i = 0; i < n; i++) {
        i64 r, h;
        cin >> r >> h, h--;
        g[r][h].emplace_back(i);
    }

    vector<i64> ans0(n), ans1(n), ans2(n);
    i64 c = 0;
    for (auto& [ r, e ] : g) {
        i64 s = e[0].size() + e[1].size() + e[2].size();
        for (auto& [ h, f ] : e) {
            for (auto& i : f) {
                ans0[i] = c + e[(h + 1) % 3].size();
                ans1[i] = n - c - s + e[(h + 2) % 3].size();
                ans2[i] = e[h].size() - 1;
            }
        }
        c += s;
    }

    for (i64 i = 0; i < n; i++) cout << ans0[i] << " " << ans1[i] << " " << ans2[i] << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
