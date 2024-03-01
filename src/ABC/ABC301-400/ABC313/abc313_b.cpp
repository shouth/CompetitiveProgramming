#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
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

  auto table = vector(N, vector(N, i64{ 0 }));
  for (i64 i = 0; i < M; ++i) {
    i64 A, B;
    cin >> A >> B, --A, --B;
    table[A][B] = 1;
  }

  for (i64 k = 0; k < N; ++k) {
    for (i64 i = 0; i < N; ++i) {
      for (i64 j = 0; j < N; ++j) {
        if (table[i][j] == 0 and table[i][k] == 1 and table[k][j] == 1) {
          table[i][j] = 1;
        }
      }
    }
  }

  for (i64 i = 0; i < N; ++i) {
    if (reduce(begin(table[i]), end(table[i]), i64{ 0 }) == N - 1) {
      cout << i + 1 << endl;
      return;
    }
  }

  cout << -1 << endl;
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
