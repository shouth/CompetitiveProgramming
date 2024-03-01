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
    i64 n;
    cin >> n;
    map<i64, i64> cnt;
    for (i64 i = 0; i < n; i++) {
        i64 l;
        cin >> l;
        cnt[l]++;
    }
    vector<i64> keys;
    for (auto& [ k, v ] : cnt) keys.emplace_back(k);
    n = keys.size();
    i64 ans = 0;
    for (i64 i = 0; i < n; i++) {
        for (i64 j = i + 1; j < n; j++) {
            for (i64 k = j + 1; k < n; k++) {
                if (keys[i] + keys[j] > keys[k]) ans += cnt[keys[i]] * cnt[keys[j]] * cnt[keys[k]];
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
