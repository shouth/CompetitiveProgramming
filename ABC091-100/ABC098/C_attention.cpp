#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> w(n), e(n);
    for (int i = n-1; i-1 >= 0; i--) e[i-1] = e[i] + (s[i] == 'E');
    for (int i = 0; i+1 < n; i++) w[i+1] = w[i] + (s[i] == 'W');

    int ans = n;
    for (int i = 0; i < n; i++) ans = min(ans, w[i] + e[i]);

    cout << ans << endl;
}
