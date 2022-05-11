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

int main() {
    int64_t n, c;
    cin >> n >> c;
    vector<int64_t> x(n), v(n);
    for (int64_t i = 0; i < n; i++) cin >> x[i] >> v[i];

    vector<int64_t> cw1(n), cw2(n), aw1(n), aw2(n);
    partial_sum(begin(v), end(v), begin(cw1));
    partial_sum(rbegin(v), rend(v), rbegin(aw1));
    cw2 = cw1;
    aw2 = aw1;

    for (int64_t i = 0; i < n; i++) {
        cw1[i] -= x[i];
        cw2[i] -= x[i] * 2;
        aw1[n-i-1] -= (c - x[n-i-1]);
        aw2[n-i-1] -= (c - x[n-i-1]) * 2;
    }

    for (int64_t i = 0; i + 1 < n; i++) {
        cw1[i+1] = max(cw1[i], cw1[i+1]);
        cw2[i+1] = max(cw2[i], cw2[i+1]);
        aw1[n-i-2] = max(aw1[n-i-2], aw1[n-i-1]);
        aw2[n-i-2] = max(aw2[n-i-2], aw2[n-i-1]);
    }

    int64_t ans = max({cw1[n-1], aw1[0], 0l});
    for (int64_t i = 0; i + 1 < n; i++) {
        ans = max({ans, cw1[i], cw2[i] + aw1[i+1], aw1[i+1], aw2[i+1] + cw1[i]});
    }

    cout << ans << endl;
}
