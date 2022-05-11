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
    i64 n, r;
    cin >> n >> r;
    string s;
    cin >> s;

    i64 ans = 0;
    i64 cnt = count(all(s), '.');
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '.') {
            for (i64 j = i; j < i + r; j++) cnt -= s[j] == '.', s[j] = 'o';
            ans++;
        } else if (i64 tmp = count(begin(s) + i, begin(s) + i + r, '.'); tmp == cnt) {
            cnt = 0;
            if (tmp != 0) ans++;
        }
        if (cnt == 0) break;
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
