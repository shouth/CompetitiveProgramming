#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 a, b;
    cin >> a >> b;
    for (i32 i = 1; i <= 1001; i++) {
        i32 na = i * 0.08;
        i32 nb = i * 0.10;
        if (na == a && nb == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
