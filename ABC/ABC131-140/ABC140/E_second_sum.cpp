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
    vector<i64> P(N);
    for (auto& e : P) cin >> e;
    vector<i64> indices(N);
    iota(all(indices), 0l);
    sort(all(indices), [&](i64 a, i64 b) { return P[a] > P[b]; });

    i64 ans = 0;
    multiset<i64> used;
    used.emplace(-1);
    used.emplace(-1);
    used.emplace(N);
    used.emplace(N);
    for (auto& e : indices) {
        auto itr = used.lower_bound(e);
        itr++;
        i64 z = *itr;
        itr--;
        i64 y = *itr;
        itr--;
        i64 x = *itr;
        itr--;
        i64 w = *itr;
        ans += P[e] * ((x - w) * (y - e) + (e - x) * (z - y));
        used.emplace(e);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
