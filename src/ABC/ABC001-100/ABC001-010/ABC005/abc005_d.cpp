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
    vector<vector<int>> d(n+1, vector<int>(n+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i+1][j+1];
            d[i+1][j+1] += d[i][j+1] + d[i+1][j] - d[i][j];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int p;
        cin >> p;
        int ans = 0;
        for (int w = 1; w <= p; w++) {
            int h = p / w;
            for (int i = 0; i < 2; i++) {
                for (int x = 0; x + w <= n; x++) {
                    for (int y = 0; y + h <= n; y++) {
                        ans = max(ans, d[x+w][y+h] - d[x][y+h] - d[x+w][y] + d[x][y]);
                    }
                }
                swap(w, h);
            }
        }

        cout << ans << endl;
    }
}
