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
    i32 n, a, b;
    cin >> n >> a >> b;
    i32 ans = n / (a + b) * a;
    n %= (a + b);
    ans += min(a, n);
    cout << ans << endl;
}
