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
    vector<int64_t> a(n);
    for (int64_t i = 0; i < n; i++) {
        int64_t ai;
        cin >> ai;
        a[i] = ai - (i + 1);
    }

    sort(begin(a), end(a));
    int64_t ans = 0;
    for (auto& e : a) ans += abs(e - a[n/2]);
    cout << ans << endl;
}
