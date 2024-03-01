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
    double t, a;
    cin >> t >> a;
    vector<int> h(n+1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    int ans = 0;
    double d = 1000;
    for (int i = 1; i <= n; i++) {
        double td = abs(a - (t - h[i] * 0.006));
        if (d > td) {
            ans = i;
            d = td;
        }
    }

    cout << ans << endl;
}
