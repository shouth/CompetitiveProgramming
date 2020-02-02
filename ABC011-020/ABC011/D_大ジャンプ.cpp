#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int x, y;
    cin >> x >> y;

    if (x % d != 0 || y % d != 0) {
        cout << 0.0 << endl;
        return 0;
    }

    int xs = n - (x + y) / d, ys = n - abs(x - y) / d;
    if (xs < 0 || xs % 2 != 0) {
        cout << 0.0 << endl;
        return 0;
    }

    vector<double> p { 1 };
    for (int i = 1; i <= n; i++) {
        vector<double> q(i+1);
        for (int j = 0; j < p.size(); j++) q[j] += p[j] / 2, q[j+1] += p[j] / 2;
        p = move(q);
    }

    cout << fixed << setprecision(20) << p[xs / 2] * p[ys / 2] << endl;
}
