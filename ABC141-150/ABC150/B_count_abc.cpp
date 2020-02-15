#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i + 3 <= n; i++) {
        if (s.substr(i, 3) == "ABC") ans++;
    }
    cout << ans << endl;
}
