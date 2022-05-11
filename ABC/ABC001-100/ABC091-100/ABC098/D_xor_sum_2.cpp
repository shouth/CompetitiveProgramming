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
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;
    for (int64_t l = 0, r = 0, x = 0; l < n; l++) {
        while (r < n && (x ^ a[r]) == (x + a[r])) x += a[r++];
        ans += r - l;

        if (l == r) r++; else x -= a[l];
    }

    cout << ans << endl;
}
