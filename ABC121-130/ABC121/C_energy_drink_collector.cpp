#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int64_t, int64_t>> ab(n);
    for(auto& e : ab) {
        cin >> e.first >> e.second;
    }
    sort(ab.begin(), ab.end());
    int64_t ans = 0;
    for(const auto& e : ab) {
        if(m > e.second) {
            m -= e.second;
            ans += e.first * e.second;
        } else {
            ans += e.first * m;
            break;
        }
    }
    cout << ans << endl;
}