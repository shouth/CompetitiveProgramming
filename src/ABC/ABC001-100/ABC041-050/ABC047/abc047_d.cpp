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
    int64_t n, t;
    cin >> n >> t;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int minp = a[0], maxb = 0, c = 0;
    for (int64_t i = 1; i < n; i++) {
        int64_t diff = a[i] - minp;
        if (diff < 0) minp = a[i];
        if (diff == maxb) c++;
        if (diff > maxb) maxb = a[i] - minp, c = 1;
    }

    cout << c << endl;
}
