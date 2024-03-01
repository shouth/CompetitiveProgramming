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
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<string> as(n);
    for (auto& e : as) cin >> e, sort(all(e));

    deque<char> ans;
    for (i64 i = (n - 1) / 2; i >= 0; i--) {
        vector<char> tmp;
        set_intersection(all(as[i]), all(as[n - 1 - i]), back_inserter(tmp));
        if (tmp.empty()) {
            cout << -1 << endl;
            return;
        }

        if (i == n - 1 - i) {
            ans.push_back(tmp[0]);
        } else {
            ans.push_front(tmp[0]);
            ans.push_back(tmp[0]);
        }
    }
    cout << string(all(ans)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
