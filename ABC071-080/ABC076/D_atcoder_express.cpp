#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n+3), v(n+2);
    for (int i = 2; i <= n+1; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    partial_sum(begin(t), end(t), begin(t));

    double p = 0, ans = 0;
    for (double a = 0; a <= t.back(); a += .5) {
        priority_queue<double, vector<double>, greater<double>> pq;
        for (int i = 0; i < n+2; i++) pq.push(v[i] + max({ t[i] - a, a - t[i+1], .0 }));
        ans += 0.25 * (p + pq.top());
        p = pq.top();
    }

    cout << fixed << setprecision(10) << ans << endl;
}
