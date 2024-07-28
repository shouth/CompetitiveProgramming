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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

auto solve() -> void
{
  i64 N, M;
  cin >> N >> M;
  auto X = vector(N, i64());
  for (auto &Xi : X) cin >> Xi;
  auto bonus = vector(N + 1, i64());
  for (i64 _ : views::iota(i64(0), M)) {
    i64 C, Y;
    cin >> C >> Y;
    bonus[C] = Y;
  }

  auto dp = vector(N + 1, i64(0));
  for (i64 i : views::iota(i64(1), N + 1)) {
    auto m = *max_element(dp.begin(), dp.end());
    for (i64 j : views::iota(i64(1), i + 1) | views::reverse) {
      dp[j] = dp[j - 1] + bonus[j] + X[i - 1];
    }
    dp[0] = m;
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
