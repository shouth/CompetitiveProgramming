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
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> xys(n);
    for (auto& e : xys) {
        int a;
        cin >> a;
        vector<pair<int, int>> xy(a);
        for (auto& f : xy) cin >> f.first >> f.second, f.first--;
        e = move(xy);
    }

    int ans = 0;
    // 1: honest, 0: not
    for (int s = 0; s < (1 << n); s++) {
        vector<int> h(n, -1);
        bool discard = false;
        for (int i = 0; i < n; i++) {
            if (!((s >> i) & 1)) continue;
            for (auto& e : xys[i]) {
                if (h[e.first] != -1 && h[e.first] != e.second) discard = true;
                if (e.second != (s >> e.first & 1)) discard = true;
                h[e.first] = e.second;
            }
        }
        if (discard) continue;
        ans = max(ans, (int) bitset<15>(s).count());
    }
    cout << ans << endl;
}
