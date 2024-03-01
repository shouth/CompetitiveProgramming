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
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, C;
    cin >> N >> C;

    vector<p64> service;
    service.reserve(2 * N);
    for (i64 i = 0; i < N; i++) {
        i64 a, b, c;
        cin >> a >> b >> c;
        service.emplace_back(a, c);
        service.emplace_back(b + 1, -c);
    }

    sort(all(service));
    i64 ans = 0;
    i64 last = 0;
    i64 total = 0;
    for (auto [ day, fee ] : service) {
        ans += (day - last) * clamp(total, 0l, C);
        total += fee;
        last = day;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
