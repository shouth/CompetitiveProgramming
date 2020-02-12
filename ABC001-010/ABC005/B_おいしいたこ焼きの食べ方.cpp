#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans = min(ans, t);
    }
    cout << ans << endl;
}
