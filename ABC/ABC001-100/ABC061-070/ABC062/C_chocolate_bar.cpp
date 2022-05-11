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
    int64_t h, w;
    cin >> h >> w;
    vector<pair<int64_t, int64_t>> d { { h, w }, { w, h } };
    int64_t ans = 1e9;
    for (auto& e : d) {
        int64_t ho = e.first, ve = e.second;
        for (int64_t i = 1; i < ho; i++) {
            int64_t hs = (ho - i) / 2;
            int64_t h1 = ve * i, h2 = ve * hs, h3 = ve * (ho - i - hs);
            ans = min(ans, max({ h1, h2, h3 }) - min({ h1, h2, h3 }));
            int64_t vs = ve / 2;
            int64_t v1 = ve * i, v2 = (ho - i) * vs, v3 = (ho - i) * (ve - vs);
            ans = min(ans, max({ v1, v2, v3 }) - min({ v1, v2, v3 }));
        }
    }

    cout << ans << endl;
}
