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
using f64 = double;
using p64 = pair<i64, i64>;

constexpr i64 INF = INT_FAST64_MAX / 2;
constexpr f64 EPS = DBL_EPSILON;

void solve() {
    i64 n;
    cin >> n;

    if (n == 1) {
        cout << "Not Prime" << endl;
        return
    }

    i64 m = n;
    for (i64 i = 2; i <= (i64) sqrt(m); i++) while (m % i == 0) m /= i;
    if (m == n) {
        cout << "Prime" << endl;
        return;
    }

    i64 sum = 0;
    for (i64 i = n; i > 0; i /= 10) sum += i % 10;
    if (n % 2 && n % 5 && sum % 3) {
        cout << "Prime" << endl;
        return;
    }

    cout << "Not Prime" << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
