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
    i64 N, W;
    cin >> N >> W;
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;

    auto eligible = vector<i64>(W + 1);
    for (i64 i = 0; i < N; i++) {
        i64 sum1 = A[i];
        if (sum1 <= W) eligible[sum1] = 1;

        for (i64 j = i + 1; j < N; j++) {
            i64 sum2 = sum1 + A[j];
            if (sum2 <= W) eligible[sum2] = 1;

            for (i64 k = j + 1; k < N; k++) {
                i64 sum3 = sum2 + A[k];
                if (sum3 <= W) eligible[sum3] = 1;
            }
        }
    }
    cout << reduce(all(eligible)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
