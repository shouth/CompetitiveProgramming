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

    vector<int> x(n), y(n), h(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

    int ax, ay, ah;
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int ch;
            for (int i = 0; i < n; i++) {
                if (h[i] == 0) continue;
                ch = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
            }
            for (int i = 0; i < n; i++) {
                if (max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0) != h[i]) break;
                if (i == n - 1) ax = cx, ay = cy, ah = ch;
            }
        }
    }

    cout << ax << " " << ay << " " << ah << endl;
}
