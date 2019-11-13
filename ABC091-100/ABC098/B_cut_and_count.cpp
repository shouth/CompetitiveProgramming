#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
        bitset<26> fh, sh;
        for (int fi = 0; fi < i; fi++) fh.set(s[fi] - 'a');
        for (int si = i; si < n; si++) sh.set(s[si] - 'a');
        ans = max(ans, (int) (fh & sh).count());
    }

    cout << ans << endl;
}
