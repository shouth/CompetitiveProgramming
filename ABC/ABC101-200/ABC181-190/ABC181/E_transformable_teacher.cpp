#include <utility>
#include <bitset>
#include <tuple>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;

    vector<i64> H(N), W(M);
    for (auto& e : H) cin >> e;
    for (auto& e : W) cin >> e;
    sort(all(H));

    vector<i64> lsum(N + 2), rsum(N + 2);
    for (i64 i = 1; i <= N; i++) lsum[i] = H[i - 1] * (i % 2 == 1 ? -1 : 1);
    for (i64 i = N; i >= 1; i--) rsum[i] = H[i - 1] * (i % 2 == 0 ? -1 : 1);
    partial_sum(all(lsum), begin(lsum));
    partial_sum(rall(rsum), rbegin(rsum));

    i64 ans = INF;
    for (auto& e : W) {
        i64 idx = upper_bound(all(H), e) - begin(H) + 1;
        if (idx % 2 == 1) idx++;
        ans = min(ans, abs(e - H[idx - 2]) + lsum[idx - 2] + rsum[idx]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
