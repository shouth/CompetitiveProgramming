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

int main() {
    int64_t a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    cout << min(x, y) * min(2 * c, a + b) + abs(x - y) * min(2 * c, x > y ? a : b) << endl;
}
