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
    i64 N;
    cin >> N;
    auto txy = vector<p64>(N);
    for (auto &[ x, y ] : txy) {
        i64 t;
        cin >> t >> x >> y;
        x = x * 2 + (t == 3 || t == 4);
        y = y * 2 - (t == 2 || t == 4);
    }

    i64 ans = 0;
    for (i64 i = 0; i < N; ++i) {
        auto [ xi, yi ] = txy[i];
        for (i64 j = i + 1; j < N; ++j) {
            auto [ xj, yj ] = txy[j];
            ans += xi <= yj && xj <= yi;
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
