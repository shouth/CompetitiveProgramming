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
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    a--;
    int64_t lcd = c * d / __gcd(c, d);
    cout << b - a - (b / c - a / c) - (b / d - a / d) + (b / lcd - a / lcd) << endl;
}
