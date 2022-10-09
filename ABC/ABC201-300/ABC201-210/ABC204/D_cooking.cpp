#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

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
#include <atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = std::numeric_limits<i64>::max() / 2;

void solve() {
    i64 N;
    cin >> N;
    auto T = vector<i64>(N);
    for (auto &e : T) cin >> e;

    auto Tsum = reduce(T.begin(), T.end());
    auto dp = vector<bool>(Tsum + 1);
    dp[0] = 1;
    for (auto &e : T) {
        for (i64 i = Tsum; i - e >= 0; --i) {
            dp[i] = dp[i] | dp[i - e];
        }
    }

    auto itr = find(dp.begin() + (Tsum + 1) / 2, dp.end(), 1);
    cout << itr - dp.begin() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
