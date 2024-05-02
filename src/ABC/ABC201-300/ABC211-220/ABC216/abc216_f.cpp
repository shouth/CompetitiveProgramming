#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numbers>
#include <numeric>
#include <optional>
#include <queue>
#include <ranges>
#include <set>
#include <span>
#include <stack>
#include <string>
#include <string_view>
#include <tuple>
#include <utility>
#include <vector>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
namespace rng = std::ranges;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint998244353;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

auto solve() -> void
{
  i64 N;
  cin >> N;
  auto AB = vector<p64>(N);
  for (auto &[ A, B ] : AB) cin >> A;
  for (auto &[ A, B ] : AB) cin >> B;

  rng::sort(AB);

  m64 ans = 0;
  auto dp = vector(AB.back().first + 1, m64(0));
  dp[0] = 1;
  for (const auto &[ A, B ] : AB) {
    if (i64 l = A - B + 1; l > 0) {
      ans += accumulate(dp.begin(), dp.begin() + l, m64(0));
    }
    for (i64 i = dp.size() - 1; i >= B; --i) {
      dp[i] += dp[i - B];
    }
  }
  cout << ans.val() << '\n';
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
