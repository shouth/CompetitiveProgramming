#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;
    vector<vector<int>> value(n, vector<int>(m));
    for (int i = 0; i < r; i++) {
        int x, y, z;
        cin >> x >> y >> z, x--, y--;
        value[x][y] = z;
    }

    int ans = 0;
    vector<int> male(m);
    for (int i = 0; i < q; i++) male[m-i-1] = 1;
    do {
        vector<int> can(n);
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (!male[y]) continue;
                can[x] += value[x][y];
            }
        }
        sort(begin(can), end(can), greater<>());
        ans = max(ans, accumulate(begin(can), begin(can) + p, 0));
    } while (next_permutation(begin(male), end(male)));
    cout << ans << endl;
}
