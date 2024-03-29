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
    i32 n, m;
    cin >> n >> m;
    vector<i32> a(n);
    i32 t = 0;
    for (auto& e : a) {
        cin >> e;
        t += e;
    }

    i32 c = 0;
    for (auto& e : a) {
        if (e * 4 * m >= t) c++;
    }
    cout << (c >= m ? "Yes" : "No") << endl;
}
