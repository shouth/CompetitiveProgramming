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
    int64_t n, m;
    cin >> n >> m;
    int64_t lcm = 1;

    int64_t d = -1;
    for (int64_t i = 0; i < n; i++) {
        int64_t a;
        cin >> a, a /= 2;

        int64_t t = 0;
        for (int64_t b = a; b % 2 == 0; b /= 2) t++;
        if (d != -1 && d != t) {
            cout << 0 << endl;
            return 0;
        }
        d = t;

        lcm = lcm * a / __gcd(lcm, a);
        if (lcm > m) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (m / lcm + 1) / 2 << endl;
}
