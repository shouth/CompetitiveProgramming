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
    i64 H, W, M;
    cin >> H >> W >> M;

    vector<i64> hcnt(H), wcnt(W);
    vector<p64> obj;
    for (i64 i = 0; i < M; i++) {
        i64 h, w;
        cin >> h >> w, h--, w--;
        hcnt[h]++, wcnt[w]++;
        obj.emplace_back(h, w);
    }

    i64 hmax = *max_element(all(hcnt));
    i64 wmax = *max_element(all(wcnt));
    i64 hmaxcnt = count(all(hcnt), hmax);
    i64 wmaxcnt = count(all(wcnt), wmax);

    i64 objcnt = count_if(all(obj), [&](auto a) {
        auto [ x, y ] = a;
        return hcnt[x] == hmax && wcnt[y] == wmax;
    });

    cout << hmax + wmax - (hmaxcnt * wmaxcnt <= objcnt) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
