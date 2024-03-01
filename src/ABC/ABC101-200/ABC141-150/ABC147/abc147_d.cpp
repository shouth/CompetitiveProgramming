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

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    int64_t ans = 0;
    for (int64_t i = 0; i < 60; i++) {
        int64_t c = 0;
        for (auto& e : a) c += ((e >> i) & 1);
        ans += (1l << i) % MOD * c % MOD * (n - c) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}
