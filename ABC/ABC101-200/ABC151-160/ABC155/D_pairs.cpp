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
using i64 = int_fast32_t;

int main() {
    i32 n, k;
    cin >> n >> k;
    vector<i32> a(n);
    i32 nn = 0, n0 = 0, np = 0;
    for (auto& e : a) {
        cin >> e;
        if (e < 0) nn++;
        if (e == 0) n0++;
        if (e > 0) np++;
    }

    i64 ans = 0;
    if (k <= nn * np) {
        vector<i64> n, p;
        for (auto& e : a) {
            if (e > 0) p.push_back(e);
            if (e < 0) n.push_back(e);
        }
        sort(begin(p), end(p));
        sort(begin(n), end(n));

        i64 bl = -INT64_MAX / 2, br = -1;
        while (abs(br - bl) > 1) {
            i64 mid = (br + bl) / 2;
            i32 count = 0;
            for (i32 ni = 0, pi = 0; ni < nn; ni++) {
                while (pi < np && n[ni] * p[pi] > mid) pi++;
                count += np - pi;
            }
            (count < k ? bl : br) = mid;
        }
        ans = br;
    } else if ((k -= nn * np + (nn + np) * n0 + n0 * (n0 - 1) / 2) > 0) {
        vector<i64> n, p;
        for (auto& e : a) {
            if (e > 0) p.push_back(e);
            if (e < 0) n.push_back(-e);
        }
        sort(begin(p), end(p));
        sort(begin(n), end(n));

        i64 bl = 0, br = INT64_MAX / 2;
        while (abs(br - bl) > 1) {
            i64 mid = (br + bl) / 2;
            i32 cnt = 0;
            for (auto& e : { n, p }) {
                i32 l = e.size();
                for (i32 i0 = 0, i1 = l-1; i0 < l; i0++) {
                    while (i1 >= 0 && e[i0] * e[i1] > mid) i1--;
                    if (e[i0] * e[i0] < mid) cnt--;
                    cnt += i1 + 1;
                }
            }

            (cnt / 2 < k ? bl : br) = mid;
        }
        ans = br;
    }

    cout << ans << endl;
}
