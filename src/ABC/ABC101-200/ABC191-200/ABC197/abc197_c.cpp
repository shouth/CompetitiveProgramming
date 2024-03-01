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
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (auto& e : A) cin >> e;

    i64 ans = INF;
    for (i64 i = 0; i < 1 << N; i++) {
        i64 pre = 0;
        i64 orsum = 0, xorsum = 0;
        for (i64 j = 0; j < N; j++) {
            if (((i >> j) & 1) == ((i >> pre) & 1)) {
                orsum |= A[j];
            } else {
                xorsum ^= orsum;
                orsum = A[j];
                pre = j;
            }
        }
        xorsum ^= orsum;
        ans = min(ans, xorsum);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
