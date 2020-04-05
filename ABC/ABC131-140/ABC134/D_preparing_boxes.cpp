#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans(n+1);
    for (int i = n; i >= 1; i--) {
        int m = 0;
        for (int j = 2; i * j <= n; j++) m += ans[i * j];
        if (m % 2 != a[i]) ans[i] = 1;
    }

    cout << accumulate(begin(ans), end(ans), 0) << endl;
    for (int i = 1; i <= n; i++) if (ans[i]) cout << i << " ";
}
