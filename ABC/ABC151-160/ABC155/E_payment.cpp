#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    int p = 1;
    for (int i = 0; i < s.size(); i++) {
        int n = s[i] - '0';
        if (n < 5) {
            ans += n;
        } else {
            ans += p + (10 - n), p = 0;
        }
    }
    cout << ans << endl;
}
