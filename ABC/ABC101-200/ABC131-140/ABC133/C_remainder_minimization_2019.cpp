#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t l, r;
    cin >> l >> r;

    int64_t ans = 9999;
    if (r - l + 1 < 2019) {
        for (int64_t i = l; i <= r - 1; i++) {
            for (int64_t j = i + 1; j <= r; j++) {
                ans = min(((i % 2019) * (j % 2019)) % 2019, ans);
            }
        }
    } else {
        ans = 0;
    }

    cout << ans << endl;
}
