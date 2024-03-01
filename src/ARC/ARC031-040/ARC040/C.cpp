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

using i64 = int_fast64_t;
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 n;
    cin >> n;
    vector<string> s(n);
    for (auto& e : s) cin >> e;

    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        i64 idx = n - 1 - distance(rbegin(s[i]), find(rall(s[i]), '.'));
        if (idx == -1) continue;
        fill(begin(s[i]), begin(s[i]) + idx + 1, 'o');
        if (i + 1 < n) fill(begin(s[i + 1]) + idx, end(s[i + 1]), 'o');
        ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
