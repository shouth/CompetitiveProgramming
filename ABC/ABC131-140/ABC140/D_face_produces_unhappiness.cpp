#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    s.push_back('E');
    int ans = 0;
    int l = 0, g = 0;
    auto c = s[0];
    for (int i = 1; i < n + 1; i++) {
        if (s[i] == c) continue;
        ans += i - l - 1;
        g++, l = i, c = s[i];
    }

    if (g / 2 <= k) {
        ans += g / 2 * 2;
        if (g % 2 == 0) ans--;
    } else {
        ans += 2 * k;
    }

    cout << ans << endl;
}
