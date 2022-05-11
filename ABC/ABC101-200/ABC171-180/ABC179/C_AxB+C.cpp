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

struct factorization {
    vector<i64> spf;

    factorization(i64 n): spf(n + 1) {
        iota(all(spf), 0);
        for (i64 i = 2; i <= n; i++) {
            if (spf[i] != i) continue;
            for (i64 j = i + i; j <= n; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    map<i64, i64> operator()(i64 n) {
        map<i64, i64> res;
        while (n > 1) {
            res[spf[n]]++;
            n /= spf[n];
        }
        return res;
    }
};

void solve() {
    i64 N;
    cin >> N;

    i64 ans = 0;
    factorization fac(N);
    for (i64 i = 1; i < N; i++) {
        auto m = fac(i);
        i64 tmp = 1;
        for (auto& [ k, v ] : m) tmp *= v + 1;
        ans += tmp;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
