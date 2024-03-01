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
    int n, k;
    cin >> n >> k;
    vector<double> r(n);
    for (auto& e : r) cin >> e;
    sort(begin(r), end(r));
    double ans = 0;
    for (int i = n-k; i < n; i++) ans = (ans + r[i]) / 2;
    cout << fixed << setprecision(15) << ans << endl;
}
