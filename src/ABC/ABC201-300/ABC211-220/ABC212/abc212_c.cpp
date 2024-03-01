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

void solve()
{
    i64 N, M;
    cin >> N >> M;
    auto AB = vector<p64>(N + M);
    for (i64 i = 0; i < N; ++i) {
        auto &[ A, isA ] = AB[i];
        cin >> A, isA = 1;
    }
    for (i64 i = N; i < N + M; ++i) {
        auto &[ B, isA ] = AB[i];
        cin >> B, isA = 0;
    }
    sort(begin(AB), end(AB));

    auto ans = INF;
    for (i64 i = 0; i + 1 < N + M; ++i) {
        auto [ x, f ] = AB[i];
        auto [ y, g ] = AB[i + 1];
        if (f != g) ans = min(ans, abs(x - y));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
