#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

i32 n;

void dfs(string ans = "", i32 d = 0, i32 use = 0) {
    if (d == n) {
        cout << ans << endl;
        return;
    }

    for (i32 i = 0; i <= min(d, use); i++) {
        dfs(ans + (char) ('a' + i), d + 1, use + (i == use));
    }
}

int main() {
    cin >> n;
    dfs();
}
