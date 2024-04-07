#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdint>
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
using m64 = modint998244353;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

auto solve() -> void
{
  i64 N;
  cin >> N;
  string S;
  cin >> S;

  auto dp = vector(2, vector(1 << 10, vector(10, m64(0))));
  for (i64 i = 0; i < N; ++i) {
    auto &current = dp[i & 1];
    auto &next = dp[(i + 1) & 1];

    for (auto &e : next) {
      ranges::fill(e, m64(0));
    }

    auto c = S[i] - 'A';
    for (u64 j = 0; j < 1 << 10; ++j) {
      for (u64 k = 0; k < 10; ++k) {
        next[j][k] += current[j][k];
        if ((j >> c) & 1) {
          if (k == c) {
            next[j][k] += current[j][k];
          }
        } else {
          next[j | (1 << c)][c] += current[j][k];
        }
      }
    }
    next[1 << c][c] += 1;
  }

  auto ans = m64(0);
  for (i64 i = 1; i < 1 << 10; ++i) {
    for (i64 j = 0; j < 10; ++j) {
      ans += dp[N & 1][i][j];
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
