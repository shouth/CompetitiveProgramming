#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

struct construction {
    i64 s, t, x;
};

void solve() {
    i64 N, Q;
    cin >> N >> Q;

    vector<construction> con(N);
    for (auto& [ s, t, x ] : con) cin >> s >> t >> x;
    sort(all(con), [](const auto &a, const auto &b) { return a.x < b.x; });

    set<p64> D;
    for (i64 i = 0; i < Q; i++) {
        i64 d;
        cin >> d;
        D.emplace(d, i);
    }

    vector<i64> ans(Q, -1);
    for (auto& [ s, t, x ] : con) {
        auto l = D.lower_bound({ s - x, -1 });
        auto r = D.lower_bound({ t - x, -1 });
        for (auto i = l; i != r; i++) ans[i->second] = x;
        D.erase(l, r);
    }

    for (auto& e : ans) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
