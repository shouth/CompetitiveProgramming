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
    i64 N, L;
    cin >> N >> L;
    auto A = priority_queue<i64, vector<i64>, greater<i64>>();
    i64 Asum = 0;
    for (i64 i = 0; i < N; i++) {
        i64 Ai;
        cin >> Ai;
        A.emplace(Ai);
        Asum += Ai;
    }
    if (i64 An = L - Asum; An > 0) A.emplace(An);

    i64 ans = 0;
    while (A.size() > 1) {
        i64 An = 0;
        An += A.top(), A.pop();
        An += A.top(), A.pop();
        ans += An;
        A.emplace(An);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
