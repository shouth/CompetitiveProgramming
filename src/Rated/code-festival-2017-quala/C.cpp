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
    i64 h, w;
    cin >> h >> w;
    map<char, i64> cnt;
    for (i64 i = 0; i < h * w; i++) {
        char a;
        cin >> a;
        cnt[a]++;
    }

    i64 r1 = 0, r2 = 0;
    for (auto& e : cnt) {
        switch (e.second % 4) {
        case 1:
            r1++;
            break;
        case 2:
            r2++;
            break;
        case 3:
            r1++, r2++;
            break;
        }
    }

    i64 c1 = (h % 2) * (w % 2);
    i64 c2 = (h % 2) * (w / 2) + (w % 2) * (h / 2);
    cout << (r1 <= c1 && r2 <= c2 ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
