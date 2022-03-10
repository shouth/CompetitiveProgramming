#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, d, a;
    cin >> n >> d >> a;
    vector<pair<int64_t, int64_t>> xh(n);
    for (auto& e : xh) cin >> e.first >> e.second;
    sort(begin(xh), end(xh));

    vector<int64_t> damage(n+1);
    int64_t ans = 0;
    for (int64_t l = 0, r = 0; l < n; l++) {
        while (r < n && xh[r].first - xh[l].first <= 2 * d) r++;
        int64_t tb = max(0l, xh[l].second - damage[l] + a - 1l) / a, ta = tb * a;
        ans += tb, damage[l] += ta, damage[r] -= ta, damage[l+1] += damage[l];
    }

    cout << ans << endl;
}
