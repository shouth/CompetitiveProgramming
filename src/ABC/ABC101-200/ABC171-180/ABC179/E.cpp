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

using namespace std;

#define all(x) begin(x), end(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, X, M;
    cin >> N >> X >> M;

    vector<i64> used(M);
    vector<i64> path;
    i64 A = X;
    for (i64 i = 0; !used[A]; i++) {
        used[A] = i;
        path.emplace_back(A);
        A = A * A % M;
    }

    i64 sum = 0;
    sum += reduce(begin(path), begin(path) + min(N, (i64) path.size()));
    N = max(0l, N - (i64) path.size());
    i64 loop = reduce(begin(path) + used[A], end(path)), len = path.size() - used[A];
    sum += N / len * loop;
    N = N % len;
    sum += reduce(begin(path) + used[A], begin(path) + used[A] + N);
    cout << sum << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
