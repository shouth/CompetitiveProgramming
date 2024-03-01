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
    i64 a, b, c;
    cin >> a >> b >> c;
    i32 d = c - a - b;
    if (d > 0 && 4 * a * b < d * d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
