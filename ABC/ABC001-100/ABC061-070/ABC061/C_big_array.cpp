#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;
    int64_t ans = 0;
    vector<pair<int, int>> ab(n);
    for (auto& e : ab) cin >> e.first >> e.second;
    sort(begin(ab), end(ab));
    int64_t c = 0;
    for (auto& e : ab) {
        c += e.second;
        if (ans == 0 && c >= k) ans = e.first;
    }
    cout << ans << endl;
}
