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
    i64 N;
    cin >> N;
    auto S = vector<string>(N);
    for (auto &e : S) cin >> e;

    auto cnt = vector<i64>(10);
    auto used = vector(N, vector<i64>(10));
    for (i64 t = 0; ; t++) {
        auto counted = vector<i64>(10);
        for (i64 i = 0; i < N; i++) {
            auto c = S[i][t % 10] - '0';
            if (counted[c]) continue;
            if (used[i][t % 10]) continue;
            used[i][t % 10] = 1;
            counted[c] = 1;
            if (++cnt[c] == N) {
                cout << t << endl;
                return;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
