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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

void solve() {
    i64 L, R;
    cin >> L >> R;

    auto factor_cnt = vector<i64>(R + 1);
    for (i64 i = 2; i <= R; ++i) {
        if (factor_cnt[i] == 0) {
            for (i64 j = i; j <= R; j += i) {
                ++factor_cnt[j];
            }
            for (i64 j = i * i; j <= R; j += i * i) {
                factor_cnt[j] = -INF;
            }
        }
    }

    i64 ans = 0;
    for (i64 i = 2; i <= R; ++i) {
        if (factor_cnt[i] >= 0) {
            i64 cnt = R / i - (L - 1) / i;
            i64 tmp = cnt * (cnt - 1) / 2;
            ans += factor_cnt[i] % 2 ? tmp : -tmp;
        }
    }
    for (i64 i = max<i64>(2, L); i <= R; ++i) {
        ans -= R / i - 1;
    }
    cout << ans * 2 << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
