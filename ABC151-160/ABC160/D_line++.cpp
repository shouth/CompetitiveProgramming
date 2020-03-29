#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, x, y;
    cin >> n >> x >> y, x--, y--;
    vector<i32> ans(n);
    for (i32 i = 0; i < n; i++) {
        for (i32 j = i+1; j < n; j++) {
            i32 d = min({ abs(j-i), abs(x-i) + 1 + abs(j-y), abs(y-i) + 1 + abs(j-x) });
            ans[d]++;
        }
    }

    for (i32 i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }
}
