#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n;
    cin >> n;
    vector<i32> ans(n);
    for (i32 i = 0; i < n-1; i++) {
        i32 a;
        cin >> a, a--;
        ans[a]++;
    }

    for (auto& e : ans) cout << e << endl;
}
