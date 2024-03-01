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

int64_t comb(int64_t n, int64_t k) {
    int64_t res = 1;
    for (int64_t i = 1, j = n; i <= k; i++, j--) res = res * j / i;
    return res;
}

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;
    map<double, int64_t, greater<>> v;
    for (int i = 0; i < n; i++) {
        int64_t vv;
        cin >> vv, v[vv]++;
    }

    double ans1 = 0;
    int64_t ans2 = 0;
    if (begin(v)->second >= a) {
        ans1 = begin(v)->first;
        for (int64_t i = a; i <= min(b, begin(v)->second); i++) ans2 += comb(begin(v)->second, i);
    } else {
        int64_t num = 0;
        for (auto& e : v) {
            if (num + e.second < a) {
                num += e.second;
                ans1 += e.first * e.second;
            } else {
                int64_t sel = a - num;
                ans1 += e.first * sel;
                ans1 /= a;
                ans2 = comb(e.second, sel);
                break;
            }
        }
    }

    cout << fixed << setprecision(10) << ans1 << "\n" << ans2 << endl;
}
