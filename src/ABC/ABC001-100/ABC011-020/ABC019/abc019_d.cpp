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
    int d = 0, m = 0;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        int t;
        cin >> t;
        if (d < t) d = t, m = i;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (m == i) continue;
        cout << "? " << m << " " << i << endl;
        int t;
        cin >> t;
        ans = max(ans, t);
    }

    cout << "! " << ans << endl;
}
