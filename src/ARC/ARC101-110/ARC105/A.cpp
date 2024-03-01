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
    vector<i64> cookies(4);
    for (auto& e : cookies) cin >> e;
    i64 sum = reduce(all(cookies));
    bool flag = false;
    for (i64 i = 0; i < 1 << 4; i++) {
        i64 tmp = 0;
        for (i64 j = 0; j < 4; j++) {
            if ((i >> j) & 1) tmp += cookies[j];
        }
        if (tmp == sum - tmp) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
