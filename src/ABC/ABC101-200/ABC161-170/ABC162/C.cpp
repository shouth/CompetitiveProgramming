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
    i32 k;
    cin >> k;

    i64 ans = 0;
    for (i32 a = 1; a <= k; a++) {
        for (i32 b = 1; b <= k; b++) {
            i32 t = gcd(a, b);
            for (i32 c = 1; c <= k; c++) {
                ans += gcd(t, c);
            }
        }
    }

    cout << ans << endl;
}
