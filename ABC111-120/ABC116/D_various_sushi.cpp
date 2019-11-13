#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int64_t, vector<int64_t>> td;
    for (size_t i = 0; i < n; i++) {
        int64_t t, d;
        cin >> t >> d;
        td[t].push_back(d);
    }

    vector<int64_t> m{0}, o{0};
    for (auto& e : td) {
        sort(begin(e.second), end(e.second));
        m.push_back(e.second.back());
        copy(begin(e.second), end(e.second) - 1, back_inserter(o));
    }

    sort(rbegin(m), rend(m) - 1);
    sort(rbegin(o), rend(o) - 1);

    for (int i = 0; i + 1 < m.size(); i++) m[i+1] += m[i];
    for (int i = 0; i + 1 < o.size(); i++) o[i+1] += o[i];

    int64_t ans = 0;
    for (int64_t x = max(1, k - ((int) o.size() - 1)); x <= min(k, (int) m.size() - 1); x++) {
        ans = max(ans, m[x] + o[k - x] + x * x);
    }

    cout << ans << endl;
}
