#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 k;
    cin >> k;
    queue<i64> q;
    for (i32 i = 1; i < 10; i++) q.push(i);

    i64 ans;
    for (i32 i = 0; i < k; i++) {
        ans = q.front(); q.pop();
        i64 d = ans % 10;
        if (d > 0) q.push(ans * 10 + d - 1);
        q.push(ans * 10 + d);
        if (d < 9) q.push(ans * 10 + d + 1);
    }

    cout << ans << endl;
}
