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
using m64 = modint998244353;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, L;
    cin >> N >> L;
    auto S = vector<i64>(N);
    for (auto &e : S) {
        string s;
        cin >> s;
        for (auto &c : s) {
            e |= 1ll << (c - 'a');
        }
    }

    auto table = vector<m64>(27);


    m64 ans = 0;
    for (i64 i = 1; i < (1 << N); i++) {
        i64 s = (1 << 26) - 1;
        for (i64 j = 0; j < N; j++) {
            if ((i >> j) & 1) s &= S[j];
        }
        i64 cnt = __builtin_popcountll(s);
        ans += __builtin_popcountll(i) & 1 ? table[cnt] : -table[cnt];
    }
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
