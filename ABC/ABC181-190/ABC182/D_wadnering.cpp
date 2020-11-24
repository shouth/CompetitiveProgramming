#include<bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (auto& e : A) cin >> e;

    partial_sum(all(A), begin(A));

    i64 msum = 0, cord = 0, ans = 0;
    for (auto& e : A) {
        msum = max(msum, e);
        ans = max(ans, cord + msum);
        cord += e;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}