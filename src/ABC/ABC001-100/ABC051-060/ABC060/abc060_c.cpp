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
    int64_t n, tt;
    cin >> n >> tt;
    vector<int64_t> t(n);
    for (auto& e : t) cin >> e;
    int64_t ans = 0;
    for (int64_t i = 0; i+1 < n; i++) ans += min(tt, t[i+1]-t[i]);
    cout << ans+tt << endl;
}
