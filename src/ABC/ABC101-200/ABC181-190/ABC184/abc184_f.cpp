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
#define rall(x) rbegin(x), rend(x)

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

void solve() {
    i64 N, T;
    cin >> N >> T;
    i64 N0 = N / 2, N1 = N - N0;
    vector<i64> A0(N0), A1(N1);
    for (auto& e : A0) cin >> e;
    for (auto& e : A1) cin >> e;

    vector<i64> sum0, sum1;
    sum0.reserve(1l << N0);
    sum1.reserve(1l << N1);

    for (i64 i = 0; i < (1l << N0); i++) {
        i64 sum = 0;
        for (i64 j = 0; j < N0; j++) {
            if ((i >> j) & 1) sum += A0[j];
        }
        if (sum > T) continue;
        sum0.emplace_back(sum);
    }
    sort(all(sum0));
    sum0.erase(unique(all(sum0)), sum0.end());

    for (i64 i = 0; i < (1l << N1); i++) {
        i64 sum = 0;
        for (i64 j = 0; j < N1; j++) {
            if ((i >> j) & 1) sum += A1[j];
        }
        if (sum > T) continue;
        sum1.emplace_back(sum);
    }
    sort(rall(sum1));
    sum1.erase(unique(all(sum1)), sum1.end());

    i64 ans = 0;
    u64 idx = 0;
    for (auto& e : sum0) {
        while (idx < sum1.size() && e + sum1[idx] > T) idx++;
        if (idx == sum1.size()) break;
        ans = max(ans, e + sum1[idx]);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
