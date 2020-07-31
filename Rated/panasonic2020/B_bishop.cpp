#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i64 h, w;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    i64 ans = w * (h / 2);
    if (h % 2 == 1) ans += (w + 1) / 2;
    cout << ans << endl;
}
