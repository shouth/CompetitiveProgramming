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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, M;
    cin >> N >> M;
    auto D = vector<i64>(N);
    for (auto &e : D) cin >> e;

    auto highway = vector(N, vector<i64>());
    for (i64 i = 0; i < M; i++) {
        i64 A, B;
        cin >> A >> B, A--, B--;
        highway[A].emplace_back(B);
        highway[B].emplace_back(A);
    }

    i64 L = N - M - 1;
    if (i64 Dsum = reduce(all(D)); Dsum != 2 * L) {
        cout << -1 << endl;
        return;
    }


}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
