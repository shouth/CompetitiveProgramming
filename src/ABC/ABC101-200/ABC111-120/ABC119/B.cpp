#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        double x;
        string u;
        cin >> x >> u;
        ans += (u == "JPY" ? x : x * 380000.0);
    }
    cout << ans << endl;
}