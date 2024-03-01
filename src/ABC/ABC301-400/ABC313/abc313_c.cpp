#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numeric>
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
  i64 N;
  cin >> N;
  auto A = vector(N, i64{});
  for (auto &e : A) {
    cin >> e;
  }

  auto avg = reduce(begin(A), end(A)) / N;
  i64 ans_l = 0;
  i64 ans_h = 0;
  for (const auto &e : A) {
    if (e <= avg) {
      ans_l += avg - e;
    } else if (e >= avg + 1) {
      ans_h += e - avg - 1;
    }
  }
  cout << max(ans_l, ans_h) << '\n';
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
