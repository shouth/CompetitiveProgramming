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
    int64_t ans = 0;
    map<pair<int, int>, int> count;
    for (int64_t m = 1; m <= n; m++) {
        int64_t d = log10(m);
        int64_t l = m / (int64_t) pow(10, d), r = m % 10;
        if (r == 0) continue;
        count[{l, r}]++;
    }

    for (int64_t m = 1; m <= n; m++) {
        int64_t d = log10(m);
        int64_t l = m / (int64_t) pow(10, d), r = m % 10;
        if (r == 0) continue;
        ans += count[{r, l}];
    }

    cout << ans << endl;
}
