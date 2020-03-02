#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

struct bit {
    vector<i32> t;
    i32 n;

    bit(i32 n): t(vector<i32>(n+1, 0)), n(n+1) {}

    void add(i32 i, i32 x) {
        for (i32 a = i; a <= n; a += a & -a) t[a] += x;
    }

    i32 sum(i32 i) {
        i32 res = 0;
        for (i32 a = i; a > 0; a -= a & -a) res += t[a];
        return res;
    }
};

int main() {
    i32 n;
    cin >> n;
    string s;
    cin >> s;
    bit t(n);
    vector<bit> count(26, bit(n));
    for (i32 i = 0; i < n; i++) {
        count[s[i] - 'a'].add(i+1, 1);
    }

    i32 q;
    cin >> q;
    for (i32 x = 0; x < q; x++) {
        i32 o;
        cin >> o;
        if (o == 1) {
            i32 i;
            char c;
            cin >> i >> c;
            count[s[i-1] - 'a'].add(i, -1);
            count[c - 'a'].add(i, 1);
            s[i-1] = c;
        } else {
            i32 l, r;
            cin >> l >> r;
            i32 ans = 0;
            for (i32 c = 0; c < 26; c++) ans += !!(count[c].sum(r) - count[c].sum(l-1));
            cout << ans << endl;
        }
    }
}
