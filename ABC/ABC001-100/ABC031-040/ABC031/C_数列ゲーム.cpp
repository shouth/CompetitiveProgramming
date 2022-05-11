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
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        int as = -1e9, ts = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int ac = 0, tc = 0;
            int l = min(i, j), r = max(i, j);
            for (int k = l; k <= r; k++) ((k-l) % 2 ? ac : tc) += a[k];
            if (ac > as) as = ac, ts = tc;
        }
        ans = max(ans, ts);
    }

    cout << ans << endl;
}
