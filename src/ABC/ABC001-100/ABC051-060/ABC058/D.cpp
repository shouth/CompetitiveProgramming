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

constexpr int64_t MOD = 1e9+7;

int main() {
    int64_t n, m;
    cin >> n >> m;
    vector<int64_t> x(n), y(m);
    for (auto& e : x) cin >> e;
    for (auto& e : y) cin >> e;
    int64_t accx = 0, accy = 0;
    for (int64_t i = 0; i+1 < n; i++) accx = (accx + (x[i+1] - x[i]) * (i+1) % MOD * (n-i-1) % MOD) % MOD;
    for (int64_t i = 0; i+1 < m; i++) accy = (accy + (y[i+1] - y[i]) * (i+1) % MOD * (m-i-1) % MOD) % MOD;
    cout << accx * accy % MOD << endl;
}
