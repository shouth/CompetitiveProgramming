#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans = "";
    for (size_t i = 0; i < s.size(); i += 2) ans += s[i];
    cout << ans << endl;
}
