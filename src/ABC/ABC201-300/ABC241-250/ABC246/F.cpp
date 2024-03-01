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
    for (i64 i = 0; i <= 26; i++) table[i] = m64(i).pow(L);

    m64 ans = 0;
    auto f = [&](auto &self, const vector<i64> &v, bool add = true) -> void {
        if (v.empty()) return;
        for (i64 i = 0; i < (i64) v.size(); i++) {
            ans += (add ? 1 : -1) * table[__builtin_popcountll(v[i])];
            auto d = vector<i64>();
            for (i64 j = 0; j < i; j++) {
                d.emplace_back(v[i] & v[j]);
            }
            self(self, d, !add);
        }
    };
    f(f, S);
    cout << ans.val() << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
