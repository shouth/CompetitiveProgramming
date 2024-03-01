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

#include<atcoder/all>

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N;
    cin >> N;

    if (N == 1) {
        cout << 0 << endl;
        return;
    }

    i64 maxq = 2, outq = 1e6 + 10;
    while (abs(outq - maxq) > 1) {
        i64 q = (outq - maxq) / 2 + maxq;
        (q * q * q < N ? maxq : outq) = q;
    }

    auto primes = vector<i64>();
    auto isprime = vector<bool>(maxq + 1, true);
    isprime[0] = isprime[1] = false;
    for (i64 q = 2; q <= maxq; q++) {
        if (!isprime[q]) continue;
        primes.emplace_back(q);
        for (i64 qq = q * 2; qq <= maxq; qq += q) {
            isprime[qq] = false;
        }
    }

    i64 ans = 0;
    for (i64 i = 0; i < (i64) primes.size(); i++) {
        i64 q = primes[i];
        i64 maxp = N / (q * q * q);
        ans += upper_bound(begin(primes), begin(primes) + i, maxp) - begin(primes);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
