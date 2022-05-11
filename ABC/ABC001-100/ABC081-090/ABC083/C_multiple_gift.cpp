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
    uint64_t x, y;
    cin >> x >> y;
    uint64_t ans = 0;
    while (x <= y) x <<= 1u, ans++;
    cout << ans << endl;
}
