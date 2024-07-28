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
  i64 N;
  u64 C;
  cin >> N >> C;

  auto X = bitset<64>(C);
  auto mapping = array<bitset<64>, 2> { u64(0), ~u64(0) };
  for (i64 _ : views::iota(i64(0), N)) {
    u64 T, A;
    cin >> T >> A;
    if (T == 1) {
      for (auto &m : mapping) m &= A;
    } else if (T == 2) {
      for (auto &m : mapping) m |= A;
    } else {
      for (auto &m : mapping) m ^= A;
    }
    for (u64 i : views::iota(u64(0), X.size())) {
      X[i] = mapping[X[i]][i];
    }
    cout << X.to_ullong() << '\n';
  }
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
