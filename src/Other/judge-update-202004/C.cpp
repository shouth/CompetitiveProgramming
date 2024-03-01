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

i32 a1, a2, a3;

i32 dfs(i32 b1, i32 b2, i32 b3, i32 n) {
    if (b1 > a1 || b2 > a2 || b3 > a3) return 0;
    if (b1 < b2 || b2 < b3) return 0;
    if (n == 0) return 1;
    return dfs(b1+1, b2, b3, n-1) + dfs(b1, b2+1, b3, n-1) + dfs(b1, b2, b3+1, n-1);
}

int main() {
    cin >> a1 >> a2 >> a3;
    cout << dfs(0, 0, 0, a1 + a2 + a3) << endl;
}
