#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

void solve() {
    i64 N, K;
    cin >> N >> K;
    auto c = vector<i64>(N);
    for (auto &e : c) cin >> e;

    auto cs = map<i64, i64>();
    i64 ans = 0;
    for (i64 i = 0; i < N; ++i) {
        ++cs[c[i]];
        if (i >= K - 1) {
            ans = max<i64>(ans, cs.size());
            if (--cs[c[i - K + 1]] == 0) {
                cs.erase(c[i - K + 1]);
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}