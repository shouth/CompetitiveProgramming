#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;

    vector<pair<int64_t, int64_t>> cb(m);
    for (auto& e : cb) cin >> e.second >> e.first;

    sort(a.begin(), a.end());
    sort(cb.begin(), cb.end(), greater<>());

    for (int ai = 0, cbi = 0; ai < n && cbi < m; cbi++) {
        if (a[ai] >= cb[cbi].first) break;

        for (int aai = ai + cb[cbi].second; a[ai] < cb[cbi].first && ai < aai && ai < n; ai++) {
            a[ai] = cb[cbi].first;
        }
    }

    cout << accumulate(a.begin(), a.end(), 0ll) << endl;
}
