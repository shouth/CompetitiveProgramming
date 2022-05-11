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
    int64_t n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;
    for (int i = 0; i+1 < n; i++) {
        if (a[i] + a[i+1] <= x) continue;
        ans += a[i] + a[i+1] - x;
        a[i+1] = a[i] > x ? 0 : x - a[i];
    }
    cout << ans << endl;
}
