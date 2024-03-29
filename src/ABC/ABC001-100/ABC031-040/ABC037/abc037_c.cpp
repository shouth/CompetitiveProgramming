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
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    partial_sum(begin(a), end(a), begin(a));

    int64_t ans = 0;
    for (int i = 0; i < n-k+1; i++) ans += a[i+k] - a[i];
    cout << ans << endl;
}
