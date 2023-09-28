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

  auto grid = vector<string>(N);
  for (auto &e : grid) cin >> e;

  auto visited = vector(N, vector<bool>(M));
  auto passed = vector(N, vector<bool>(M));
  auto q = queue<p64>();
  q.emplace(1, 1);

  while (not q.empty()) {
    auto [ y, x ] = q.front();
    q.pop();

    if (visited[y][x]) continue;

    visited[y][x] = 1;
    for (auto [ dy, dx ] : std::vector<p64>{ { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } }) {
      auto ny = y, nx = x;
      while (ny + dy >= 0 and ny + dy < N and nx + dx >= 0 and nx + dx < M and grid[ny + dy][nx + dx] == '.') {
        passed[ny][nx] = 1;
        ny += dy, nx += dx;
      }
      q.emplace(ny, nx);
    }
  }

  i64 ans = 0;
  for (i64 y = 0; y < N; ++y) {
    for (i64 x = 0; x < M; ++x) {
      if (passed[y][x] or visited[y][x]) ++ans;
    }
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
