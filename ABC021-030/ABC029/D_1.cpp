#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for (int64_t d = 10, e = 1; d <= 1e10; d *= 10, e *= 10) {
        ans += n / d * e;
        if (n % d / e == 1) {
            ans += n % d - (e - 1);
        } else if (n % d / e > 1) {
            ans += e;
        }
    }

    cout << ans << endl;
}
