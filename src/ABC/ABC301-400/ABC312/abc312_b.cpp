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
  i64 N, M;
  cin >> N >> M;
  auto S = vector<string>(N);
  for (auto &e : S) cin >> e;

  auto check = [&](i64 y, i64 x, vector<string> pattern) -> bool {
    for (i64 i = 0; i < pattern.size(); ++i) {
      if (S[y + i].substr(x, pattern[i].size()) != pattern[i]) {
        return false;
      }
    }
    return true;
  };

  for (i64 y = 0; y + 8 < N; ++y) {
    for (i64 x = 0; x + 8 < M; ++x) {
      auto up_left = vector<string> {
        "###.",
        "###.",
        "###.",
        "....",
      };
      auto down_right = vector<string> {
        "....",
        ".###",
        ".###",
        ".###",
      };
      if (check(y, x, up_left) and check(y + 5, x + 5, down_right)) {
        cout << y + 1 << " " << x + 1 << "\n";
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
