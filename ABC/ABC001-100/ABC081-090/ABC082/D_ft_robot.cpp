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
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    s += 'T';
    auto ft = find(begin(s), end(s), 'T');
    int xx = ft - begin(s);
    s = string(ft + 1, end(s));
    vector<int> xs, ys;
    for (int l = 0, r = 0, c = 0; r < s.size(); r++) {
        if (s[r] != 'T') continue;
        (c++ % 2 == 1 ? xs : ys).push_back(r - l);
        l = r + 1;
    }

    vector<bitset<18000>> xdp(xs.size() + 1), ydp(ys.size() + 1);
    int origin = 9000;
    xdp[0][xx + origin] = ydp[0][origin] = 1;
    for (int i = 0; i < xs.size(); i++) {
        for (int j = -9000; j < 9000; j++) {
            if (!xdp[i][j + origin]) continue;
            if (j + xs[i] < 9000) xdp[i+1][j + xs[i] + origin] = 1;
            if (j - xs[i] >= -9000) xdp[i+1][j - xs[i] + origin] = 1;
        }
    }
    for (int i = 0; i < ys.size(); i++) {
        for (int j = -9000; j < 9000; j++) {
            if (!ydp[i][j + origin]) continue;
            if (j + ys[i] < 9000) ydp[i+1][j + ys[i] + origin] = 1;
            if (j - ys[i] >= -9000) ydp[i+1][j - ys[i] + origin] = 1;
        }
    }

    cout << (xdp[xs.size()][x + origin] && ydp[ys.size()][y + origin] ? "Yes" : "No") << endl;
}
