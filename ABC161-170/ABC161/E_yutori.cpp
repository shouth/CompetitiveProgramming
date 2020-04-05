#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<i32> l(k), r(k);
    for (i32 i = 0, d = 0; i < k; i++) {
        while (s[d] == 'x') d++;
        l[i] = d;
        d += c + 1;
    }
    for (i32 i = k-1, d = n-1; i >= 0; i--) {
        while (s[d] == 'x') d--;
        r[i] = d;
        d -= c + 1;
    }

    for (i32 i = 0; i < k; i++) {
        if (l[i] == r[i]) cout << l[i] + 1 << endl;
    }
}
