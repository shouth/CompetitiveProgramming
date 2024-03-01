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

auto solve() -> void
{
  i64 N;
  cin >> N;
  auto wuv = vector<tuple<i64, i64, i64>>(N - 1);
  for (auto &[ w, u, v ] : wuv) cin >> u >> v >> w, --u, --v;
  sort(begin(wuv), end(wuv));

  auto ds = dsu(N);
  i64 ans = 0;
  for (auto &[ w, u, v ] : wuv) {
    ans += ds.size(u) * ds.size(v) * w;
    ds.merge(u, v);
  }
  cout << ans << endl;
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
