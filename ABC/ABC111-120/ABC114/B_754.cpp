#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 999;
    for (int i = 0; i + 2 < s.length(); i++) {
        ans = min(ans, abs(753 - (s[i] - '0') * 100 - (s[i+1] - '0') * 10 - (s[i+2] - '0')));
    }

    cout << ans << endl;
}
