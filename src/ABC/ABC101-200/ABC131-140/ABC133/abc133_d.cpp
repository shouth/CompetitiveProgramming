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
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t t = accumulate(begin(a), end(a), 0) / 2;
    vector<int64_t> al(n), ar(n);
    al[0] = a[0], al[1] = a[1];
    ar[n-1] = a[n-1], ar[n-2] = a[n-2];
    for (int i = 0; i + 2 < n; i += 2) al[i+2] = a[i+2] + al[i];
    for (int i = 1; i + 2 < n; i += 2) al[i+2] = a[i+2] + al[i];
    for (int i = n - 1; i - 2 >= 0; i -= 2) ar[i-2] = a[i-2] + ar[i];
    for (int i = n - 2; i - 2 >= 0; i -= 2) ar[i-2] = a[i-2] + ar[i];

    for (int i = 0; i < n; i++) {
        int ans = t;
        if (i - 2 >= 0) ans -= al[i - 2];
        if (i + 1 < n) ans -= ar[i + 1];
        cout << ans * 2 << " ";
    }
}
