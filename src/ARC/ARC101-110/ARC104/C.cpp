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
    i64 N;
    cin >> N;

    vector<i64> passenger(2 * N + 1, -1); // 乗り降りする人
    vector<i64> paired(2 * N + 1, -1); // 対の階
    for (i64 i = 0; i < N; i++) {
        i64 A, B;
        cin >> A >> B;
        if (A != -1) {
            if (passenger[A] != -1) {
                cout << "No" << endl;
                return;
            }
            passenger[A] = i;
        }
        if (B != -1) {
            if (passenger[B] != -1) {
                cout << "No" << endl;
                return;
            }
            passenger[B] = i;
        }
        if (A != -1 && B != -1) {
            if (paired[A] != -1 || paired[B] != -1 || A >= B) {
                cout << "No" << endl;
                return;
            }
            paired[A] = B, paired[B] = A;
        }
    }

    vector<i64> dp(2 * N + 1);
    dp[0] = dp[1] = true;
    for (i64 i = 0; i < 2 * N; i++) {
        if (!dp[i]) continue;
        for (i64 j = i + 2; j <= 2 * N; j += 2) {
            i64 m = (j - i) / 2;
            bool flag = true;
            for (i64 k = 1; k <= m; k++) {
                i64 l = i + k, r = i + k + m;
                if (passenger[l] != -1 && passenger[r] != -1 && passenger[l] != passenger[r]) {
                    flag = false;
                    break;
                }
                if ((paired[l] != -1 && paired[l] != r) || (paired[r] != -1 && paired[r] != l)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                dp[j] = true;
            }
        }
    }
    cout << (dp[2 * N] ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
