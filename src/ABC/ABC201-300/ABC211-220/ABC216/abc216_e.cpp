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

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include <atcoder/all>

#pragma clang diagnostic pop

using namespace std;
using namespace atcoder;
namespace rng = std::ranges;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

auto solve() -> void
{
  i64 N, K;
  cin >> N >> K;
  auto A = vector<i64>(N);
  for (auto &Ai : A)
    cin >> Ai;

  i64 l = -1, r = 2e9 + 10;
  while (r - l > 1) {
    i64 m = (l + r) / 2;

    i64 cnt = 0;
    for (auto Ai : A) {
      cnt += max(0L, Ai - m + 1);
    }

    (cnt > K ? l : r) = m;
  }

  for (auto Ai : A) {
    K -= max(0L, Ai - r + 1);
  }
  i64 ans = max(0L, r - 1) * K;
  for (auto Ai : A) {
    ans += max(0L, (Ai - r + 1) * (Ai + r) / 2);
  }
  cout << ans << '\n';
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
