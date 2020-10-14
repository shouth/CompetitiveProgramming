#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;

    vector<i64> w(N);
    for (auto& e : w) cin >> e;
    vector<i64> l(M), v(M);
    for (i64 i = 0; i < M; i++) cin >> l[i] >> v[i];

    i64 minl = *min_element(all(v));
    if (any_of(all(w), [&](i64 x) { return x > minl; })) {
        cout << -1 << endl;
        return;
    }

    
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
