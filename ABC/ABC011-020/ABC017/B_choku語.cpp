#include<bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;
    int n = x.size();
    string ans = "YES";
    for (int i = 0; i < n; i++) {
        if (x[i] == 'o' || x[i] == 'k' || x[i] == 'u') continue;
        if (x[i++] == 'c' && x[i] == 'h') continue;
        ans = "NO";
        break;
    }

    cout << ans << endl;
}
