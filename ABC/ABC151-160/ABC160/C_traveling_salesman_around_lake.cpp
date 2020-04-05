#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 k, n;
    cin >> k >> n;
    vector<i64> a(n*2);
    for (i32 i = 0; i < n; i++) {
        i32 t;
        cin >> t;
        a[i] = t;
        a[i+n] = t + k;
    }

    i64 ans = INT64_MAX;
    for (i32 i = 0; i <= n; i++) {
        ans = min(ans, a[i+n-1] - a[i]);
    }

    cout << ans << endl;
}
