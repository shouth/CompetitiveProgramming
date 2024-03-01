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
    vector<i64> a(n);
    map<i64, i64> c;
    i64 ans = 0;
    for (auto& e : a) {
        cin >> e;
        ans += c[e]++;
    }

    for (auto& e : a) {
        cout << ans - (c[e] - 1) << endl;
    }
}
