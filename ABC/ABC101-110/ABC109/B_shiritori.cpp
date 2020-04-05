#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> w;
    string c, ans = "Yes";
    for (int i = 0; i < n; i++) {
        string n;
        cin >> n;
        w[n]++;
        if (i != 0 && c.back() != n[0]) ans = "No";
        c = n;
    }

    for (auto e : w) if (e.second != 1) ans = "No";

    cout << ans << endl;
}
