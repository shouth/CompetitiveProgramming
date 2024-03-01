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

i64 f(i64 x) {
    i64 res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve() {
    i64 n;
    cin >> n;

    i64 cnt = 0;
    vector<i64> ans;
    for (i64 i = 1; i < 170; i++) {
        i64 x = n - i;
        if (i == f(x)) cnt++, ans.emplace_back(x);
    }
    sort(all(ans));
    cout << cnt << endl;
    for (auto& e : ans) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
