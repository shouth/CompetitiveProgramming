#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> w(n), b(n+1);
    b[n] = 0; 
    for (int i = 0, wc = 0; i < n; i++) {
        if (s[i] == '.') wc++;
        w[i] = wc;
    }
    for (int i = n-1, bc = 0; i >= 0; i--) {
        if (s[i] == '#') bc++;
        b[i] = bc;
    }
    int ans = n - b[0];
    for (int i = 0; i < n; i++) {
        ans = min(n - w[i] - b[i+1], ans);
    }
    cout << ans << endl;
}