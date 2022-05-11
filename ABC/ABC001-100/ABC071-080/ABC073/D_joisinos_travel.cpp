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
    int n, m, rr;
    cin >> n >> m >> rr;
    vector<int> r(rr);
    for (auto& e : r) cin >> e, e--;
    sort(begin(r), end(r));
    vector<vector<int>> ab(n, vector<int>(n, 1e9));
    for (int i = 0; i < n; i++) ab[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        ab[a][b] = ab[b][a] = c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                ab[j][k] = min(ab[j][k], ab[j][i] + ab[i][k]);
            }
        }
    }

    int ans = 1e9;
    do {
        int tmp = 0;
        for (int i = 0; i + 1 < rr; i++) {
            tmp += ab[r[i]][r[i+1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(begin(r), end(r)));

    cout << ans << endl;
}
