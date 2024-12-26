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
  u64 N, K;
  cin >> N >> K;

  auto Ts = vector<u64>(N);
  for (u64 i = 0; i < K + 1; ++i) {
    cout << "?";
    for (u64 j = 0; j < K + 1; ++j) {
      if (i != j) {
        cout << " " << j + 1;
      }
    }
    cout << endl;
    cin >> Ts[i];
  }
  for (u64 i = K + 1; i < N; ++i) {
    cout << "?";
    for (u64 j = 0; j < K - 1; ++j) {
      cout << " " << j + 1;
    }
    cout << " " << i + 1;
    cout << endl;
    cin >> Ts[i];
  }

  auto S = reduce(Ts.begin(), Ts.begin() + K + 1) % 2;

  auto A = vector<u64>(N);
  for (u64 i = 0; i < K + 1; ++i) {
    A[i] = (S + Ts[i]) % 2;
  }
  for (u64 i = K + 1; i < N; ++i) {
    A[i] = (Ts[i] + Ts[K] + A[K - 1]) % 2;
  }

  cout << "!";
  for (u64 i = 0; i < N; ++i) {
    cout << " " << A[i];
  }
  cout << endl;
}

auto main() -> int
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  solve();
}
