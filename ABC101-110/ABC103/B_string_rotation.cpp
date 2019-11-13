#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    string r = s;

    string ans = "No";
    do {
        rotate(rbegin(r), rbegin(r) + 1, rend(r));
        if (r == t) ans = "Yes";
    } while (r != s);

    cout << ans << endl;
}
