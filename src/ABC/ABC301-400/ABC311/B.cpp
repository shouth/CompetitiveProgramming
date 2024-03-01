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
  i64 N, D;
  cin >> N >> D;

  auto T = string(D, 'o');
  auto S = string();
  for (i64 i = 0; i < N; ++i) {
    cin >> S;
    for (i64 d = 0; d < D; ++d) {
      if (S[d] == 'x') T[d] = 'x';
    }
  }

  auto ans = u64(0);
  for (auto view = string_view(T.data(), T.size()); not view.empty();) {
    auto oi = min<u64>(view.size(), view.find('x'));
    ans = max<u64>(ans, oi);
    view = view.substr(oi);
    auto xi = min<u64>(view.size(), view.find('o'));
    view = view.substr(xi);
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
