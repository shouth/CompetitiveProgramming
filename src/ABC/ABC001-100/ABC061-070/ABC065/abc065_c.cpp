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
array<int64_t, 100'010> fac;

int main() {
    fac[0] = 1;
    for (int i = 0; i+1 < 100'010; i++) fac[i+1] = fac[i] * (i+1) % MOD;
    int64_t n, m;
    cin >> n >> m;
    int ans = 0, a = abs(n-m);
    if (a <= 1) {
        ans = fac[n] * fac[m] % MOD;
        if (a == 0) ans = ans * 2 % MOD;
    }
    cout << ans << endl;
}
