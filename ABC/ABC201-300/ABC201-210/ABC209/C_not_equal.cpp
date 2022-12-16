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
    auto C = vector<i64>(N);
    for (auto &e : C) cin >> e;
    sort(begin(C), end(C));

    m64 ans = 1;
    for (i64 i = 0; i < N; ++i) {
        ans *= max<i64>(0, C[i] - i);
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
