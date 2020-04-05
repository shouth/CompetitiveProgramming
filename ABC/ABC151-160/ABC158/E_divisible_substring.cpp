#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, p;
    cin >> n >> p;
    i32 r = 1, d = 0;
    map<int, int> rg;
    for (i32 i = n-1; i >= 0; i--) {
        char c;
        cin >> c;
        i32 e = c - '0';
        d = (d + r * e) % p;
        rg[d]++;
        r = (r * 10) % p;
    }

    i32 ans = 0;
    for (auto& e : rg) {
        ans += e.second * (e.second - 1) / 2;
        if (e.first == 0) ans += e.second;
    }

    cout << ans << endl;
}
