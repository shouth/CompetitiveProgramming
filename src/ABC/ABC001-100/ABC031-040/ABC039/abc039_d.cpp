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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto& e : s) cin >> e;

    vector<string> ans(h, string(w, '#'));
    vector<int> dxy { 0, 1, -1, -1, 0, 0, -1, 1, 1, 0 };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;

            for (int d = 0; d < 9; d++) {
                int ni = i + dxy[d], nj = j + dxy[d+1];
                if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
                ans[ni][nj] = '.';
            }
        }
    }

    bool possibility = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool containb = false;
            for (int d = 0; d < 9; d++) {
                int ni = i + dxy[d], nj = j + dxy[d+1];
                if (ni < 0 || h <= ni || nj < 0 || w <= nj) continue;
                if (ans[ni][nj] == '#') containb = true;
            }

            if (containb ^ (s[i][j] == '#')) possibility = false;
        }
    }

    if (possibility) {
        cout << "possible" << endl;
        for (auto& e : ans) cout << e << endl;
    } else {
        cout << "impossible" << endl;
    }
}
