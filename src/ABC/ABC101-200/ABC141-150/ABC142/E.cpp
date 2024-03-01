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

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, m;
    cin >> n >> m;

    vector<i32> a(m);
    vector<i32> c(m);
    for (i32 i = 0; i < m; i++) {
        i32 b;
        cin >> a[i] >> b;

        for (i32 j = 0; j < b; j++) {
            i32 ci;
            cin >> ci, ci--;
            c[i] |= 1 << ci;
        }
    }

    vector<i32> dp(1 << n, INT32_MAX / 2);
    dp[0] = 0;
    for (i32 i = 0; i < m; i++) {
        for (i32 j = (1 << n) - 1; j >= 0; j--) {
            dp[j | c[i]] = min(dp[j | c[i]], dp[j] + a[i]);
        }
    }

    cout << (dp[(1 << n) - 1] == INT32_MAX / 2 ? -1 : dp[(1 << n) - 1]) << endl;
}
