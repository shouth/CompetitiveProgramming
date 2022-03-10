#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;

    map<int, int> odd {{-1, -1}}, even {{-1, -1}};
    for (int i = 0; i < n; i++) (i % 2 ? odd : even)[v[i]]++;

    vector<pair<int, int>> ov(begin(odd), end(odd)), ev(begin(even), end(even));
    sort(begin(ov), end(ov), [](auto a, auto b) { return a.second > b.second; });
    sort(begin(ev), end(ev), [](auto a, auto b) { return a.second > b.second; });

    int ans = 1e6;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (ov[i].first == ev[j].first) ans = min(ans, min(n - ov[i].second, n - ev[j].second));
            else ans = min(ans, (n + 1) / 2 - ov[i].second + n / 2 - ev[j].second);
        }
    }

    cout << ans << endl;
}
