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

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;
    for (i64 i = 1; i <= 3500; i++) {
        for (i64 j = 1; j <= 3500; j++) {
            i64 k1 = n * i * j;
            i64 k2 = 4 * i * j - n * (i + j);
            if (k2 > 0 && k1 % k2 == 0) {
                cout << i << " " << j << " " << k1 / k2 << endl;
                return;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
