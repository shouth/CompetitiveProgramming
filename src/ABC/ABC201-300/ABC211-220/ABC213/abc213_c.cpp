#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"

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

#pragma clang diagnostic pop

void solve()
{
    i64 H, W, N;
    cin >> H >> W >> N;
    auto AB = vector<p64>(N);
    for (auto &[ A, B ] : AB) cin >> A >> B;

    auto amap = map<i64, i64>();
    auto bmap = map<i64, i64>();

    for (auto &[ A, B ] : AB) {
        amap.insert_or_assign(A, 0);
        bmap.insert_or_assign(B, 0);
    }

    i64 index = 0;
    for (auto &[ k, v ] : amap) {
        v = ++index;
    }
    index = 0;
    for (auto &[ k, v ] : bmap) {
        v = ++index;
    }

    for (auto &[ A, B ] : AB) {
        cout << amap[A] << " " << bmap[B] << "\n";
    }
    cout << endl;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
