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
    i64 Q;
    cin >> Q;

    i64 bsum = 0, asum = 0;
    priority_queue<i64> l;
    priority_queue<i64, vector<i64>, greater<>> r;
    {
        i64 t;
        cin >> t;
        i64 a, b;
        cin >> a >> b;
        bsum += b;
        l.emplace(a);
        r.emplace(a);
    }
    for (i64 i = 1; i < Q; i++) {
        i64 t;
        cin >> t;

        if (t == 1) {
            i64 a, b;
            cin >> a >> b;
            bsum += b;

            i64 ltop = l.top(), rtop = r.top();
            if (ltop > a) {
                l.emplace(a);
                l.emplace(a);
                r.emplace(ltop);
                l.pop();
                asum += ltop - a;
            } else if (rtop < a) {
                r.emplace(a);
                r.emplace(a);
                l.emplace(rtop);
                r.pop();
                asum += a - rtop;
                continue;
            } else {
                l.emplace(a);
                r.emplace(a);
            }
        } else {
            cout << l.top() << " " << asum + bsum << endl;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
