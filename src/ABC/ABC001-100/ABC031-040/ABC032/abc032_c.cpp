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
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> s(n);
    for (auto& e : s) cin >> e;
    s.push_back(1e9+1);
    int64_t ans = 0;
    for (int64_t l = 0, r = 0, p = 1; l < n; l++) {
        if (s[l] == 0) {
            ans = n;
            break;
        }
        while (r < n && p * s[r] <= k) p *= s[r], r++;
        ans = max(ans, r - l);
        if (r == l) r++;
        else p /= s[l];
    }
    cout << ans << endl;
}
