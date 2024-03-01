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
    vector<vector<char>> g(h, vector<char>(w));
    vector<bool> rows(h), cols(w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') rows[i] = cols[j] = true;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (rows[i] && cols[j]) cout << g[i][j];
        }
        if (rows[i]) cout << endl;
    }
}
