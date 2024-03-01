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
    map<i64, i64, greater<>> cnt;
    for (i64 i = 0; i < n; i++) {
        i64 a;
        cin >> a;
        cnt[a]++;
    }

    i64 ans = 0;
    for (auto& e : cnt) {
        i64 a, c;
        tie(a, c) = e;
        i64 b = (1l << ((i64) log2(a) + 1)) - a;
        if (a == b) {
            ans += cnt[a] / 2;
            continue;
        }
        if (cnt.find(b) == cnt.end()) continue;
        i64 p = min(cnt[b], c);
        ans += p, cnt[b] -= p;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
