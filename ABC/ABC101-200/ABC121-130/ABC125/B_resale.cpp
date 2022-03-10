#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v(n), c(n);
    for (auto& e : v) cin >> e;
    for (auto& e : c) cin >> e; 
    for (int i=0; i<n; i++) {
        if (v[i] - c[i] > 0) ans += v[i] - c[i];
    }
    cout << ans << endl;
    return 0;
}
