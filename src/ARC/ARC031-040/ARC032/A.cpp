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
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;

    if (n == 1) {
        cout << "BOWWOW" << endl;
        return;
    }

    i64 m = n * (n + 1) / 2;
    for (i64 i = 2; i <= (i64) sqrt(m); i++) {
        if (m % i == 0) {
            cout << "BOWWOW" << endl;
            return;
        }
    }

    cout << "WANWAN" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
