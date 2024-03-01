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
    int64_t n, k;
    cin >> n >> k;

    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;

    for (int64_t b = 1ll << 50, ka = 0; b >= 0; b >>= 1) {
        int64_t tmp = 0;
        for (auto& e : a) tmp += e & b;

        if (ka + b > k || tmp > n * b - tmp) {
            ans += tmp;
        } else {
            ans += n * b - tmp;
            ka += b;
        }
    }

    cout << ans << endl;
}
