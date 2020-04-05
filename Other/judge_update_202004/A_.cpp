#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 s, l, r;
    cin >> s >> l >> r;
    if (s < l) s = l;
    if (s > r) s = r;
    cout << s << endl;
}
