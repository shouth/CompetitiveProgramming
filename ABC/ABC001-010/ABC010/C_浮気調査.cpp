#include<bits/stdc++.h>
using namespace std;

int main() {
    double txa, tya, txb, tyb;
    int t, v;
    cin >> txa >> tya >> txb >> tyb >> t >> v;
    int n;
    cin >> n;
    string ans = "NO";
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        double d = hypot(txa - x, tya - y) + hypot(txb - x, tyb - y);
        if (d <= t * v) ans = "YES";
    }
    cout << ans << endl;
}
