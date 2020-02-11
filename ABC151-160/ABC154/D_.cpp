#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> p(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] = (p[i] + 1.0) / 2.0;
    }
    partial_sum(begin(p), end(p), begin(p));
    double ans = 0;
    for (int i = 0; i+k <= n; i++) {
        ans = max(ans, p[i+k]-p[i]);
    }
    cout << fixed << setprecision(15) << ans << endl;
}
