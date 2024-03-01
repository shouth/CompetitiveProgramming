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
#define yes(x) ((x) ? "yes" : "no")
#define Yes(x) ((x) ? "Yes" : "No")

using i64 = int_fast64_t;
using u64 = uint_fast64_t;
using f64 = double_t;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;

i64 g1(i64 x) {
    string s = to_string(x);
    sort(all(s), greater<>());
    return stoi(s);
}

i64 g2(i64 x) {
    string s = to_string(x);
    sort(all(s));
    return stoi(s);
}

i64 f(i64 x) {
    return g1(x) - g2(x);
}

void solve() {
    i64 N, K;
    cin >> N >> K;
    for (i64 i = 0; i < K; i++) N = f(N);
    cout << N << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
