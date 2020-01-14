#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    int w;
    cin >> w;
    int ans = s <= w && w <= t;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        w += a, ans += s <= w && w <= t;
    }
    cout << ans << endl;
}
