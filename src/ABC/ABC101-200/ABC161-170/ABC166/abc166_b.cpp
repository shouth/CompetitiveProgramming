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
    i64 n, k;
    cin >> n >> k;
    vector<i64> snuke(n);
    for (i64 i = 0; i < k; i++) {
        i64 d;
        cin >> d;
        for (i64 j = 0; j < d; j++) {
            i64 a;
            cin >> a, a--;
            snuke[a]++;
        }
    }

    cout << count(begin(snuke), end(snuke), 0) << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
