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
    i32 x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<i32> p(a), q(b), r(c);
    for (auto& e : p) cin >> e;
    for (auto& e : q) cin >> e;
    for (auto& e : r) cin >> e;
    sort(begin(p), end(p), greater<>());
    sort(begin(q), end(q), greater<>());
    sort(begin(r), end(r), greater<>());

    vector<i32> apple;
    for (i32 i = 0; i < x; i++) apple.push_back(p[i]);
    for (i32 i = 0; i < y; i++) apple.push_back(q[i]);
    for (i32 i = 0; i < min(x+y, c); i++) apple.push_back(r[i]);
    sort(begin(apple), end(apple), greater<>());

    cout << accumulate(begin(apple), begin(apple) + x + y, 0l) << endl;
}
