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

using i64 = int_fast64_t;
using f64 = double;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> b(n);
    for (auto& e : b) cin >> e, e--;

    deque<i64> ans;
    for (i64 i = n - 1; i >= 0; i--) {
        for (i64 j = i; j >= 0; j--) {
            if (b[j] == j) {
                b.erase(begin(b) + j);
                ans.push_front(j + 1);
                break;
            }
        }
    }

    if (!b.empty()) {
        cout << -1 << endl;
        return;
    }

    for (auto& e : ans) cout << e << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
