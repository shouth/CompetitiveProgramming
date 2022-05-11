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

#include<atcoder/all>

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

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    string S;
    cin >> S;

    i64 ans = 0;
    for (i64 n = 0; n < 10000; n++) {
        i64 contain[10] { };
        for (i64 m = n, i = 0; i < 4; i++) {
            contain[m % 10]++;
            m /= 10;
        }

        bool ok = true;
        for (i64 i = 0; i < 10; i++) {
            if (S[i] == 'o') {
                if (!contain[i]) {
                    ok = false;
                    break;
                }
            } else if (S[i] == 'x') {
                if (contain[i]) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
