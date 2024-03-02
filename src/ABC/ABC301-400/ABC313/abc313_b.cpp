#include <bitset>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <utility>

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

  auto table = std::array<std::bitset<50>, 50>{};
  for (i64 i = 0; i < N; ++i) {
    table[i][i] = true;
  }

  for (i64 i = 0; i < M; ++i) {
    i64 A, B;
    cin >> A >> B, --A, --B;
    table[A][B] = true;
  }

  for (i64 k = 0; k < N; ++k) {
    for (i64 i = 0; i < N; ++i) {
      for (i64 j = 0; j < N; ++j) {
        table[i][j] = table[i][j] | (table[i][k] & table[k][j]);
      }
    }
  }

  for (i64 i = 0; i < N; ++i) {
    if (table[i].count() == N) {
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
