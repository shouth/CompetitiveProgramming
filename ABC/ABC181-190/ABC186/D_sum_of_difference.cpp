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
    vector<i64> A(N);
    for (auto& e : A) cin >> e;

    sort(all(A));
    partial_sum(all(A), begin(A));
    i64 ans = 0;
    for (i64 i = 0; i + 1 < N; i++) {
        ans += (i + 1) * (A[i + 1] - A[i]) - A[i];
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
