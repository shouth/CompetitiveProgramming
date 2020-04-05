#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, ix;
    cin >> n >> ix;
    vector<int> x(n);
    for (auto& e : x) cin >> e;
    x.push_back(ix);
    sort(begin(x), end(x));
    int s = x[0];
    for (auto& e : x) e -= s;
    vector<int> d;
    for (int i = 0; i + 1 < x.size(); i++) d.push_back(x[i+1] - x[i]);
    int ans = d[0];
    for (int i = 1; i < x.size(); i++) ans = __gcd(ans, d[i]);
    cout << ans << endl;
}
