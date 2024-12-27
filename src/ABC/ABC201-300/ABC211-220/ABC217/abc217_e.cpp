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

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

auto solve() -> void
{
  u64 Q;
  cin >> Q;

  auto pq = priority_queue<u64, vector<u64>, greater<u64>>();
  auto xs = queue<u64>();
  for (auto _ : views::iota(u64(), Q)) {
    u64 t;
    cin >> t;
    if (t == 1) {
      u64 x;
      cin >> x;
      xs.emplace(x);
    } else if (t == 2) {
      if (not pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
      } else {
        cout << xs.front() << '\n';
        xs.pop();
      }
    } else {
      while (not xs.empty()) {
        pq.emplace(xs.front());
        xs.pop();
      }
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
