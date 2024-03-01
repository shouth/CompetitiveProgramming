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

vector<i64> basen(i64 x, i64 n) {
    vector<i64> res;
    while (x > 0) {
        res.push_back(x % n);
        x /= n;
    }
    reverse(all(res));
    return res;
}

i64 cmp(vector<i64> a, vector<i64> b) {
    if (i64 d = b.size() - a.size()) return d;
    for (i64 i = 0; i < (i64) b.size(); i++) {
        if (i64 d = b[i] - a[i]) return d;
    }
    return 0;
}

void solve() {
    string X;
    cin >> X;
    i64 M;
    cin >> M;

    if (X.size() == 1) {
        i64 x = stoll(X);
        cout << (x <= M ? 1 : 0) << endl;
        return;
    }

    vector<i64> x;
    for (auto& e : X) x.push_back(e - '0');
    i64 d = *max_element(all(x));
    i64 l = d, r = INF;

    while (abs(r - l) > 1) {
        i64 m = (r - l) / 2 + l;
        (cmp(x, basen(M, m)) < 0 ? r : l) = m;
    }
    cout << l - d << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
