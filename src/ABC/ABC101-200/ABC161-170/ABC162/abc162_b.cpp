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
    i64 n;
    cin >> n;
    cout << n * (n + 1) / 2 - (n / 3) * (n / 3 + 1) / 2 * 3 - (n / 5) * (n / 5 + 1) / 2 * 5 + (n / 15) * (n / 15 + 1) / 2 * 15 << endl;
}
