#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, m;
    cin >> n >> m;
    i32 a = 0;
    for (i32 i = 0; i < m; i++) {
        i32 t;
        cin >> t;
        a += t;
    }

    cout << (n-a < 0 ? -1 : n-a) << endl;
}
