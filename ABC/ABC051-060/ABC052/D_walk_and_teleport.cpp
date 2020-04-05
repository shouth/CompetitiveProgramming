#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, a, b;
    cin >> n >> a >> b;
    vector<int64_t> x(n);
    for (auto& e : x) cin >> e;

    int64_t ans = 0;
    for (int i = 0; i+1 < n; i++) ans += min((x[i+1]-x[i])*a, b);
    cout << ans << endl;
}
