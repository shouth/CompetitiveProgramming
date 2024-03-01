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

constexpr int INF = 1e9;

using board = vector<vector<int>>;

map<board, int> m;
board b(2, vector<int>(3)), c(3, vector<int>(2));
board s {{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }};

int dfs(int d = 0) {
    if (m.find(s) != m.end()) return m[s];

    int res = d % 2 ? INF : -INF;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i][j] != 0) continue;
            s[i][j] = d % 2 ? -1 : 1;
            res = d % 2 ? min(res, dfs(d+1)) : max(res, dfs(d+1));
            s[i][j] = 0;
        }
    }

    if (abs(res) == INF) {
        res = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i < 2) res += s[i][j] == s[i+1][j] ? b[i][j] : -b[i][j];
                if (j < 2) res += s[i][j] == s[i][j+1] ? c[i][j] : -c[i][j];
            }
        }
        return res;
    }

    return res;
}

int main() {
    int t = 0;
    for (auto& e : b) for (auto& f : e) cin >> f, t += f;
    for (auto& e : c) for (auto& f : e) cin >> f, t += f;
    int ans = dfs();
    cout << (t + ans) / 2 << "\n" << (t - ans) / 2 << endl;
}
