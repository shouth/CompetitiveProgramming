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
using m64 = modint998244353;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

#pragma clang diagnostic pop

auto solve() -> void
{
  auto S = string{};
  cin >> S;

  i64 n = S.size();
  auto dp = vector(2, vector(n + 1, m64{}));
  dp[0][0] = 1;
  for (i64 i = 0; i < n; ++i) {
    auto &current = dp[i % 2];
    auto &next = dp[(i + 1) % 2];
    next.assign(n + 1, 0);
    for (i64 j = 0; j <= n; ++j) {
      if (S[i] == '(') {
        if (j + 1 <= n) {
          next[j + 1] += current[j];
        }
      } else if (S[i] == ')') {
        if (j - 1 >= 0) {
          next[j - 1] += current[j];
        }
      } else {
        if (j + 1 <= n) {
          next[j + 1] += current[j];
        }
        if (j - 1 >= 0) {
          next[j - 1] += current[j];
        }
      }
    }
  }
  cout << dp[n % 2][0].val() << endl;
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
