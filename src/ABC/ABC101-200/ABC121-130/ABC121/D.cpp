#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b;
    cin >> a >> b;
    auto f = [&](int64_t n, int64_t mod) {
        int64_t n01 = (n+1) / (mod*2), s = (n+1) % (mod*2);
        return n01 * mod + (s > mod ? s - mod : 0);
    };
    int64_t ans = 0;
    for(size_t i = 0; i < 50; i++) {
        int64_t mod = 1ll << i, af = f(a-1, mod), bf = f(b, mod);
        ans += ((bf - af) % 2 != 0 ? mod : 0);
    }
    cout << ans << endl;
}