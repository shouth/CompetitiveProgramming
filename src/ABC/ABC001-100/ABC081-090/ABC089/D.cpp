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
    int h, w, d;
    cin >> h >> w >> d;
    vector<pair<int, int>> a(h*w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int aij;
            cin >> aij;
            a[aij-1] = { i, j };
        }
    }

    vector<int> acc(h*w);
    for (int i = 0; i + d < h * w; i++) {
        acc[i+d] = acc[i] + abs(a[i+d].first - a[i].first) + abs(a[i+d].second - a[i].second);
    }

    int q;
    cin >> q;
    vector<pair<int, int>> lr(q);
    for (auto& e : lr) {
        cin >> e.first >> e.second;
        e.first--, e.second--;
    }
    for (auto& e : lr) cout << acc[e.second] - acc[e.first] << endl;
}
