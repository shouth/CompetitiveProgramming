#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    string n;
    cin >> n;

    i32 dp0 = 0, dp1 = 1;
    for (auto& e : n) {
        i32 d = e - '0';
        tie(dp0, dp1) = make_tuple(
            min(dp0 + d, dp1 + (10 - d)),
            min(dp0 + d + 1, dp1 + (10 - (d + 1))));
    }

    cout << dp0 << endl;
}
