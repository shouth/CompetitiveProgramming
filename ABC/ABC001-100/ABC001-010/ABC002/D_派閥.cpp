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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = 1 << i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        a[x] |= (1 << y), a[y] |= (1 << x);
    }

    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int g = i;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) g &= a[j];
        }
        ans = max(ans, __builtin_popcount(g));
    }

    cout << ans << endl;
}
