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
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

vector<i64> prime_table(i64 n) {
    auto res = vector<i64>(n + 1);
    iota(all(res), 0);
    if (n >= 0) res[0] = 0;
    if (n >= 1) res[1] = 0;
    for (i64 i = 2; i * i <= n; i++) {
        if (!res[i]) continue;
        for (i64 j = i * i; j <= n; j += i) {
            res[j] = 0;
        }
    }
    return res;
}

vector<i64> prime_number(i64 n) {
    auto res = prime_table(n);
    res.erase(remove_if(all(res), logical_not<i64>()), res.end());
    return res;
}

void solve() {
    i64 A, B;
    cin >> A >> B;

    auto prime = prime_number(B - A);
    auto factor = vector<i64>(B - A + 1);
    for (i64 x = A; x <= B; x++) {
        for (i64 i = 0; i < (i64) prime.size(); i++) {
            if (x % prime[i] == 0) {
                factor[x - A] |= 1ll << i;
            }
        }
    }

    auto dp = vector<i64>(1 << prime.size());
    dp[0] = 1;
    for (auto &e : factor) {
        for (i64 i = 0; i < (1 << prime.size()); i++) {
            if (!(i & e)) {
                dp[i | e] += dp[i];
            }
        }
    }
    cout << std::reduce(all(dp)) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
