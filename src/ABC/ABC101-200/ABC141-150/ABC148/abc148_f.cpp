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
    i32 n, u, v;
    cin >> n >> u >> v, u--, v--;
    vector<vector<i32>> t(n);
    for (i32 i = 0; i < n-1; i++) {
        i32 a, b;
        cin >> a >> b, a--, b--;
        t[a].push_back(b);
        t[b].push_back(a);
    }

    vector<i32> takahashi(n, -1);
    queue<i32> q;
    takahashi[u] = 0;
    q.push(u);
    while (!q.empty()) {
        i32 i = q.front(); q.pop();
        for (auto& e : t[i]) {
            if (takahashi[e] != -1) continue;
            takahashi[e] = takahashi[i] + 1;
            q.push(e);
        }
    }

    vector<i32> aoki(n, -1);
    aoki[v] = 0;
    q.push(v);
    while (!q.empty()) {
        i32 i = q.front(); q.pop();
        for (auto& e : t[i]) {
            if (aoki[e] != -1) continue;
            aoki[e] = aoki[i] + 1;
            q.push(e);
        }
    }

    i32 p = v;
    for (i32 i = 0; i < n; i++) {
        if (t[i].size() != 1) continue;
        if (takahashi[i] >= aoki[i]) continue;
        if (aoki[p] < aoki[i]) p = i;
    }

    cout << aoki[p] - 1 << endl;
}
