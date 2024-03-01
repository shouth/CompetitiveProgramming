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
    int64_t n, h;
    cin >> n >> h;
    int64_t a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int64_t ans = INT64_MAX;
    for (int64_t x = 0; x <= n; x++) {
        int64_t t = e * (n - x) - (h + x * b);
        int64_t y = t < 0 ? 0l : t / (d + e) + 1;
        if (n < x + y) continue;
        ans = min(ans, a * x + c * y);
    }

    cout << ans << endl;
}
