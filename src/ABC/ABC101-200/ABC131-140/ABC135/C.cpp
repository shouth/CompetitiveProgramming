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
    int64_t n;
    cin >> n;
    vector<int64_t> a(n+1), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    auto la = a, lb = b;
    for (int i = 0; i + 1 <= n; i++) {
        if (la[i] > lb[i]) {
            la[i] -= lb[i];
            lb[i] = 0;
        } else {
            lb[i] -= la[i];
            la[i] = 0;
        }

        if (la[i+1] > lb[i]) {
            la[i+1] -= lb[i];
        } else {
            la[i+1] = 0;
        }
    }

    auto ra = a, rb = b;
    for (int i = n; i - 1 >= 0; i--) {
        if (ra[i] > rb[i-1]) {
            ra[i] -= rb[i-1];
            rb[i-1] = 0;
        } else {
            rb[i-1] -= ra[i];
            ra[i] = 0;
        }

        if (ra[i-1] > rb[i-1]) {
            ra[i-1] -= rb[i-1];
        } else {
            ra[i-1] = 0;
        }
    }

    auto sum = accumulate(begin(a), end(a), 0ll);
    cout << max(sum - accumulate(begin(la), end(la), 0ll), sum - accumulate(begin(ra), end(ra), 0ll)) << endl;
}
