#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& e : c) cin >> e;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (c[i] % c[j] == 0) f[i]++;
        }
    }

    double ans = 0;
    for (auto& e : f) ans += (double) (e / 2 + 1) / (double) (e + 1);
    cout << fixed << setprecision(15) << ans << endl;
}
