#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for (auto& e : l) cin >> e;

    int d = 0;
    int ans = 1;
    for (auto e : l) {
        if (d + e > x) break;

        d += e;
        ans++;
    }

    cout << ans << endl;
}
