#pragma clang diagnostic ignored "-Wunused-variable"
#pragma clang diagnostic ignored "-Wunused-const-variable"

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

using namespace std;
using namespace atcoder;

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;
using m64 = modint1000000007;

constexpr i64 INF = numeric_limits<i64>::max() / 2;

void solve() {
    i64 N;
    cin >> N;
    auto A = vector<i64>(N);
    for (auto &e : A) cin >> e;

    auto m = map<i64, i64>();
    i64 cnt = 0;
    for (auto &e : A) {
        if (m.count(e) == 0) {
            m[e] = cnt++;
        }
        e = m[e];
    }

    auto ds = dsu(cnt);
    for (i64 i = 0; i < N - 1 - i; ++i) {
        ds.merge(A[i], A[N - 1 - i]);
    }

    auto gcnt = vector<i64>(cnt);
    i64 ans = 0;
    for (i64 i = 0; i < cnt; ++i) {
        ++gcnt[ds.leader(i)];
    }

    for (auto e : gcnt) {
        if (e != 0) {
            ans += e - 1;
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
