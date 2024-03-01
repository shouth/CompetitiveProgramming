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
    vector<i32> v(n), u(n);
    v[0] = 1;
    for (i32 i = 0; i < m; i++) {
        i32 s, c;
        cin >> s >> c, s--;
        if (u[s] && v[s] != c) {
            cout << -1 << endl;
            return 0;
        }
        u[s] = 1;
        v[s] = c;
    }

    if (n != 1 && v[0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 1 && u[0] == 0) {
        v[0] = 0;
    }
    for (auto& e : v) cout << e;
    cout << endl;
}
