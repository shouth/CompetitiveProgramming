#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

#include <functional>
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
  auto A = vector<i64>(N);
  for (auto &e : A) cin >> e;
  auto B = vector<i64>(M);
  for (auto &e : B) cin >> e;

  sort(begin(A), end(A));
  sort(begin(B), end(B), greater{});

  i64 l = 0;
  i64 h = 1e9 + 10;
  while (h - l > 1) {
    i64 m = (h - l) / 2 + l;
    auto ac = upper_bound(begin(A), end(A), m) - begin(A);
    auto bc = upper_bound(begin(B), end(B), m, greater{}) - begin(B);
    (ac >= bc ? h : l) = m;
  }
  cout << h << endl;
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
