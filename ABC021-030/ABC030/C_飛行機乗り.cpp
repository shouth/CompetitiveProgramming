#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(m);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    int t = 0, ans = 0;
    while (true) {
        auto itr1 = lower_bound(begin(a), end(a), t);
        if (itr1 == end(a)) break;
        t = *itr1 + x;
        auto itr2 = lower_bound(begin(b), end(b), t);
        if (itr2 == end(b)) break;
        t = *itr2 + y;
        ans++;
    }
    cout << ans << endl;
}
