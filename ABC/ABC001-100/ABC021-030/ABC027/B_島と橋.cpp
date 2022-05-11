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
    int t = 0, s = 0;
    vector<int> a(n);
    for (auto& e : a) cin >> e, t += e;
    s = t, s /= n;

    int ans = 0;
    if (s * n != t) {
        ans = -1;
    } else for (int l = 0, r = 0, sum = 0; r < n;) {
        sum += a[r++];
        if (sum != (r-l) * s) continue;
        ans += r-l-1;
        l = r, sum = 0;
    }

    cout << ans << endl;
}
