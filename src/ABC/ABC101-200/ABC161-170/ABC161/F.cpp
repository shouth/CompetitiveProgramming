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

bool isok(i64 n, i64 x) {
    while (n % x == 0) n /= x;
    return n % x == 1;
}

int main() {
    i64 n;
    cin >> n;

    i32 ans = n > 2 ? 2 : 1;
    for (i64 i = 2, lim = sqrt(n); i <= lim; i++) {
        if (n % i != 0) continue;
        if (isok(n, i)) ans++;
        if (n / i == i) continue;
        if (isok(n, n / i)) ans++;
    }

    n--;
    for (i64 i = 2, lim = sqrt(n); i <= lim; i++) {
        if (n % i != 0) continue;
        ans++;
        if (n / i == i) continue;
        ans++;
    }

    cout << ans << endl;
}
