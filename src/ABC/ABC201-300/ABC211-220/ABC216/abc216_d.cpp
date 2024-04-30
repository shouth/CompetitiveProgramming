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
namespace rng = std::ranges;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

auto solve() -> void
{
  i64 N, M;
  cin >> N >> M;
  auto a = vector<queue<i64>>(M);
  for (auto &ai : a) {
    i64 k;
    cin >> k;
    for (i64 j = 0; j < k; ++j) {
      i64 aij;
      cin >> aij;
      ai.push(aij);
    }
  }

  auto b = vector<i64>(N + 1, -1);
  auto q = queue<i64>();
  for (i64 i = 0; i < M; ++i) {
    q.push(i);
  }

  while (not q.empty()) {
    auto i = q.front();
    q.pop();

    auto aij = a[i].front();
    if (b[aij] == -1) {
      b[aij] = i;
    } else {
      a[i].pop();
      a[b[aij]].pop();
      if (not a[i].empty()) {
        q.push(i);
      }
      if (not a[b[aij]].empty()) {
        q.push(b[aij]);
      }
    }
  }

  auto ans = rng::all_of(a, [](auto &ai) { return ai.empty(); });
  cout << (ans ? "Yes" : "No") << '\n';
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
