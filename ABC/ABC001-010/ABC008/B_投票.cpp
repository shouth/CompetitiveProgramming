#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> c;
    string ans = "";
    int x = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (x < ++c[s]) {
            x = c[s];
            ans = s;
        }
    }

    cout << ans << endl;
}
