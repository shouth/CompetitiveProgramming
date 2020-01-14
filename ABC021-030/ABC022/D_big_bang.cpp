#include<bits/stdc++.h>
using namespace std;

using point = pair<double, double>;

signed main() {
    int n;
    cin >> n;
    vector<point> ap(n), bp(n);
    point agp, bgp;
    for (auto& e : ap) {
        cin >> e.first >> e.second;
        agp.first += e.first, agp.second += e.second;
    }
    for (auto& e : bp) {
        cin >> e.first >> e.second;
        bgp.first += e.first, bgp.second += e.second;
    }

    agp.first /= n, agp.second /= n;
    bgp.first /= n, bgp.second /= n;

    double mad = 0, mbd = 0;
    for (auto& e : ap) mad = max(mad, hypot(e.first - agp.first, e.second - agp.second));
    for (auto& e : bp) mbd = max(mbd, hypot(e.first - bgp.first, e.second - bgp.second));

    cout << fixed << setprecision(15) << mbd / mad << endl;
}
