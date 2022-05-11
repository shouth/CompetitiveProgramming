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

int64_t f(int64_t n) {
    string s = to_string(n);
    int64_t dp0 = 0, dp1 = 1;
    for (int64_t i = 0; i < s.size(); i++) {
        dp0 = dp0 * 8 + dp1 * (s[i] - '0' - (s[i] > '4'));
        dp1 &= s[i] != '4' && s[i] != '9';
    }
    return n + 1 - (dp0 + dp1);
}

int main() {
    int64_t a, b;
    cin >> a >> b;
    cout << f(b) - f(a-1) << endl;
}
