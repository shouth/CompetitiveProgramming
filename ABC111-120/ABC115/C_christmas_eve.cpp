#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int64_t> h(n);
    for (auto& e : h) cin >> e;

    sort(begin(h), end(h));
    int64_t ans = 1e10;
    for (int i = 0; i + k - 1 < n; i++) ans = min(ans, h[i+k-1] - h[i]);
    cout << ans << endl;
}
