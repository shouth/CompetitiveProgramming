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
    i64 N, W;
    cin >> N >> W;

    auto supply = vector(2e5 + 1, i64(0));
    for (i64 _ = 0; _ < N; _++) {
        i64 S, T, P;
        cin >> S >> T >> P;
        supply[S] += P, supply[T] -= P;
    }
    partial_sum(all(supply), begin(supply));

    bool flag = all_of(all(supply), [&](auto x) { return x <= W; });
    cout << (flag ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
