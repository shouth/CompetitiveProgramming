#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> r(n);
    for (auto& e : r) cin >> e;
    if (n % 2) r.push_back(0);
    sort(begin(r), end(r), greater<>());
    double ans = 0;
    for (int i = 0; i < (int) r.size(); i += 2) {
        ans += M_PI * (r[i] * r[i] - r[i+1] * r[i+1]);
    }

    cout << fixed << setprecision(15) << ans << endl;
}
