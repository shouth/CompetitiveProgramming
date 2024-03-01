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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> acc(2*k+1, vector<int>(2*k+1));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        char c;
        cin >> c;
        if (c == 'W') y += k;
        x %= 2*k, y %= 2*k;
        acc[x+1][y+1]++;
    }

    for (int i = 0; i + 1 <= 2*k; i++) {
        for (int j = 0; j + 1 <= 2*k; j++) {
            acc[i+1][j+1] += acc[i][j+1] + acc[i+1][j] - acc[i][j];
        }
    }

    int ans = 0;
    vector<pair<int, int>> v = { { 0, 0 }, { -k, -k }, { -k, k }, { k, k }, { k, -k } };
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int can = 0;
            for (auto& e : v) {
                int ax = i + e.first, ay = j + e.second;
                int bx = ax + k, by = ay + k;
                for (auto& f : { &ax, &ay, &bx, &by }) {
                    *f = max(0, *f);
                    *f = min(2*k, *f);
                }
                can += acc[bx][by] - acc[bx][ay] - acc[ax][by] + acc[ax][ay];
            }
            ans = max(ans, can);
            ans = max(ans, n - can);
        }
    }

    cout << ans << endl;
}
