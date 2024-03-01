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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, q;
    cin >> n >> q;
    vector<i32> a(n);
    for (auto& e : a) cin >> e;
    partial_sum(begin(a), end(a), begin(a), gcd<i32, i32>);

    for (i32 i = 0; i < q; i++) {
        i32 s;
        cin >> s;

        if (i32 ans = gcd(s, a.back()); ans != 1) {
            cout << ans << endl;
            continue;
        }

        i32 l = -1, r = n-1;
        while (abs(r - l) > 1) {
            i32 mid = (l + r) / 2;
            (gcd(s, a[mid]) != 1 ? l : r) = mid;
        }

        cout << r+1 << endl;
    }
}
