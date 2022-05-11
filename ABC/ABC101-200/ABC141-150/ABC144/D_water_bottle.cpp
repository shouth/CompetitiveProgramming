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
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;

    if (a * b / 2 >= x) a = x * 2 / b;
    else b = (a * b - x) * 2 / a;

    cout << fixed << setprecision(10) << atan(b / a) / 3.14159265358 * 180 << endl;
}
