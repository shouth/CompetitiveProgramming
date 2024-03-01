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
    i64 na, nb;
    cin >> na >> nb;
    map<i64, i64> cnt;
    i64 x = 0, y = 0;
    for (i64 i = 0; i < na + nb; i++) {
        i64 t;
        cin >> t;
        if (cnt[t] == 0) x++;
        if (cnt[t] == 1) y++;
        cnt[t]++;
    }

    cout << (f64) y / (f64) x << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
