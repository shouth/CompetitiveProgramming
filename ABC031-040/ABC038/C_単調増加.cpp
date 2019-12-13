#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n+1);
    for (int64_t i = 0; i < n; i++) cin >> a[i];
    a[n] = -1;

    int64_t ans = 0;
    for (int64_t l = 0, r = 1; r < n+1; r++) {
        if (a[r-1] < a[r]) continue;
        ans += (r-l+1) * (r-l) / 2;
        l = r;
    }

    cout << ans << endl;
}
