#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    map<string, int64_t> s;
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        sort(t.begin(), t.end());
        ans += s[t]++;
    }

    cout << ans << endl;
}
