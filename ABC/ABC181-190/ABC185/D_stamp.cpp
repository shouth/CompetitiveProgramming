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
    i64 N, M;
    cin >> N >> M;
    vector<i64> A(M);
    for (auto& e : A) cin >> e;
    if (N == M) {
        cout << 0 << endl;
        return;
    }
    A.emplace_back(0);
    A.emplace_back(N + 1);
    sort(all(A));

    vector<i64> diff;
    diff.reserve(M + 1);
    for (i64 i = 0; i < M + 1; i++) {
        i64 tmp = A[i + 1] - A[i] - 1;
        if (tmp) diff.emplace_back(tmp);
    }

    i64 ans = 0;
    i64 m = *min_element(all(diff));
    for (auto& e : diff) ans += (e + m - 1) / m;
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}