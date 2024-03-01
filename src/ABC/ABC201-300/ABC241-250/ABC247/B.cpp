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

    auto st = vector<pair<string, string>>(N);
    for (auto &[ s, t ] : st) {
        cin >> s >> t;
    }

    for (i64 i = 0; i < N; i++) {
        auto &[ s, t ] = st[i];

        bool sok = true, tok = true;
        for (i64 j = 0; j < N; j++) {
            if (i == j) continue;

            auto &[ ss, tt ] = st[j];
            if (s == ss || s == tt) sok = false;
            if (t == ss || t == tt) tok = false;
        }

        if (!sok && !tok) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
