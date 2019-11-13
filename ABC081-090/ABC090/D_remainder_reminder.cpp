#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;

    int64_t ans = 0;
    for (int64_t i = 1; i <= n - k; i++) {
        ans += n / (k + i) * i + max(0l, n % (k + i) - (k - 1) * (k != 0));
    }

    cout << ans << endl;
}
