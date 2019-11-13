#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n-1);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    for (auto& e : c) cin >> e;

    int ans = 0;
    for (int i = 0; i < n; i++) ans += b[a[i]-1];
    for (int i = 0; i < n-1; i++) if (a[i] + 1 == a[i+1]) ans += c[a[i]-1];
    cout << ans << endl;
}
