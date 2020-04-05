#include<bits/stdc++.h>
using namespace std;

using pint = pair<int64_t, int64_t>;

vector<pint> enumerate(
    vector<pint>::iterator b,
    vector<pint>::iterator e) {
    int64_t n = e - b;
    vector<pint> tmp(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) continue;
            tmp[i].first += b[j].second;
            tmp[i].second += b[j].first;
        }
    }

    sort(begin(tmp), end(tmp));
    vector<pint> res;
    int64_t maxv = 0;
    for (auto& elem : tmp) {
        if (maxv > elem.second) continue;
        res.push_back(elem);
        maxv = elem.second;
    }

    return res;
}

int main() {
    int64_t n, w;
    cin >> n >> w;
    vector<pint> vw(n);
    int64_t vmax = 0, wmax = 0, vt = 0, wt = 0;
    for (auto& e : vw) {
        cin >> e.first >> e.second;
        vmax = max(vmax, e.first), wmax = max(wmax, e.second);
        vt += e.first, wt += e.second;
    }

    int64_t ans = 0;

    if (n <= 30) {
        vector<pint> fe = enumerate(begin(vw), begin(vw) + n/2);
        vector<pint> se = enumerate(begin(vw) + n/2, end(vw));

        int i = se.size() - 1;
        for (auto& e : fe) {
            if (e.first > w) break;
            while (e.first + se[i].first > w && i >= 0) i--;
            if (e.first + se[i].first > w) break;
            ans = max(ans, e.second + se[i].second);
        }
    } else if (wmax <= 1000) {
        int64_t limw = min(w, wt);
        vector<int64_t> dp(limw+1, -1e18);
        dp[0] = 0;

        for (int64_t i = 0; i < n; i++) {
            for (int64_t j = limw; j >= vw[i].second; j--) {
                dp[j] = max(dp[j], dp[j-vw[i].second] + vw[i].first);
            }
        }

        for (auto& e : dp) {
            ans = max(ans, e);
        }
    } else if (vmax <= 1000) {
        vector<int64_t> dp(vt+1, 1e18);
        dp[0] = 0;

        for (int64_t i = 0; i < n; i++) {
            for (int64_t j = vt; j >= vw[i].first; j--) {
                dp[j] = min(dp[j], dp[j-vw[i].first] + vw[i].second);
            }
        }

        for (int64_t i = 0; i <= vt; i++) {
            if (dp[i] > w) continue;
            ans = i;
        }
    }

    cout << ans << endl;
}
