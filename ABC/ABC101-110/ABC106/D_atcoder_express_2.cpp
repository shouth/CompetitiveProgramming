#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> acc(n+1, vector<int>(n+1, 0));
    for (int i = 0; i < m; i++) {
        int li, ri;
        cin >> li >> ri;
        acc[li][ri]++;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j + 1 <= n; j++) {
            acc[i][j+1] += acc[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j + 1 <= n; j++) {
            acc[j+1][i] += acc[j][i];
        }
    }

    vector<int> ans(q);
    for (auto& e : ans) {
        int pi, qi;
        cin >> pi >> qi;
        e = acc[qi][qi] - acc[qi][pi-1] - acc[pi-1][qi] + acc[pi-1][pi-1];
    }

    for (auto& e : ans) cout << e << endl;
}
