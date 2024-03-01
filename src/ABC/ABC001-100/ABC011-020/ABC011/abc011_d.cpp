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
    int n, d;
    cin >> n >> d;
    int x, y;
    cin >> x >> y;

    if (x % d != 0 || y % d != 0) {
        cout << 0.0 << endl;
        return 0;
    }

    int xs = n - (x + y) / d, ys = n - abs(x - y) / d;
    if (xs < 0 || xs % 2 != 0) {
        cout << 0.0 << endl;
        return 0;
    }

    vector<double> p(n+1);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) p[j] /= 2, p[j+1] += p[j];
    }

    cout << fixed << setprecision(20) << p[xs / 2] * p[ys / 2] << endl;
}
