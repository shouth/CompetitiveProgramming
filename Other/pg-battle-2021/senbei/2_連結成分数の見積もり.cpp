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
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 T;
    cin >> T;

    for (ssize_t i = 0; i < T; i++) {
        i64 N, M;
        cin >> N >> M;

        i64 l = 0, r = N;
        while (abs(r - l) > 1) {
            i64 n = (r + l) / 2;
            (n * (n - 1) / 2 >= M ? r : l) = n;
        }
        cout << std::max(N - M, 1l) << " " << N - r + 1 << "\n";
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
