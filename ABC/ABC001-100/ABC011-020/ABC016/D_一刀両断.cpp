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
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    int n;
    cin >> n;
    vector<pair<int, int>> xy(n);
    for (auto& e : xy) cin >> e.first >> e.second;

    int p = 0;
    for (int i = 0; i < n; i++) {
        int j = (i+1) % n;
        int px, py, qx, qy;
        tie(px, py) = xy[i], tie(qx, qy) = xy[j];
        int sa = (ax - bx) * (py - ay) + (ay - by) * (ax - px);
        int sb = (ax - bx) * (qy - ay) + (ay - by) * (ax - qx);
        int ta = (px - qx) * (ay - py) + (py - qy) * (px - ax);
        int tb = (px - qx) * (by - py) + (py - qy) * (px - bx);
        if (((sa > 0) ^ (sb > 0)) && ((ta > 0) ^ (tb > 0))) p++;
    }

    cout << (p + 2) / 2 << endl;
}
