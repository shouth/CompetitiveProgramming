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
#include <atcoder/all>

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
    i64 A, B, C, D;
    cin >> A >> B >> C >> D;

    auto isprime = vector<bool>(B + D + 1, 1);
    isprime[0] = isprime[1] = 0;
    for (i64 i = 2; i < isprime.size(); i++) {
        if (!isprime[i]) continue;
        for (i64 j = i + i; j < isprime.size(); j += i) isprime[j] = 0;
    }

    for (i64 x = A; x <= B; x++) {
        bool flag = reduce(begin(isprime) + x + C, begin(isprime) + x + D + 1, 0, bit_or());
        if (!flag) {
            cout << "Takahashi" << endl;
            return;
        }
    }
    cout << "Aoki" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
