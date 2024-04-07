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
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

auto solve() -> void
{
  i64 N, M;
  cin >> N >> M;

  auto flags = vector<bool>(M + 1, true);
  for (i64 i = 0; i < N; ++i) {
    i64 A;
    cin >> A;

    for (i64 k = 1; k * k <= A and k <= M; ++k) {
      if (A % k == 0) {
        if (k > 1 and flags[k]) {
          for (i64 j = k; j <= M; j += k) {
            flags[j] = false;
          }
        }

        i64 x = A / k;
        if (x > 1 and x <= M and flags[x]) {
          for (i64 j = x; j <= M; j += x) {
            flags[j] = false;
          }
        }
      }
    }
  }

  cout << count(flags.begin() + 1, flags.end(), true) << '\n';
  for (i64 k = 1; k <= M; ++k) {
    if (flags[k]) {
      cout << k << '\n';
    }
  }
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
