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

using i64 = int_fast64_t;
using f64 = double;

void solve() {
    i64 t1, t2;
    cin >> t1 >> t2;
    i64 a1, a2;
    cin >> a1 >> a2;
    i64 b1, b2;
    cin >> b1 >> b2;
    i64 c1 = (a1 - b1) * t1, c2 = (a2 - b2) * t2;

    if (c1 + c2 == 0) {
        cout << "infinity" << endl;
        return;
    }

    if ((c1 ^ (c1 + c2)) >= 0) {
        cout << 0 << endl;
        return;
    }

    i64 r = abs(c1), d = abs(c1 + c2);
    cout << (r / d) * 2 + (r % d != 0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
