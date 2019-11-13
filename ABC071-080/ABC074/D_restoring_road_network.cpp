#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<vector<int64_t>> g(n, vector<int64_t>(n));
    for (auto& e : g) for (auto& f : e) cin >> f;
    
    bitset<90000> c;
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < n; j++) {
            for (int64_t k = j + 1; k < n; k++) {
                if (g[j][k] == g[j][i] + g[i][k] && i != j && j != k && k != i) {
                    c.set(j*n+k);
                } else if (g[j][k] > g[j][i] + g[i][k]) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    int64_t ans = 0;
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = i + 1; j < n; j++) {
            if (!c[i*n+j]) ans += g[i][j];
        }
    }
    cout << ans << endl;
}
