#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1e9, ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (m >= a) ans++;
        m = min(m, a);
    }
    cout << ans << endl;
}
