#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    vector<pair<int, int>> xy(n);
    for (auto& e : xy) cin >> e.first >> e.second;
    vector<int> s(n);
    iota(begin(s), end(s), 0);
    double ans = 0;
    do {
        for (int i = 0; i + 1 < n; i++) {
            ans += hypot(xy[s[i]].first - xy[s[i+1]].first, xy[s[i]].second - xy[s[i+1]].second);
        }
    } while (next_permutation(begin(s), end(s)));

    cout << fixed << setprecision(10) << ans / f << endl;
}
