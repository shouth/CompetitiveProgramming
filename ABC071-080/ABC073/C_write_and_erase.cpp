#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int aa;
        cin >> aa;
        a[aa]++;
    }
    int ans = 0;
    for (auto& e : a) {
        if (e.second % 2 == 1) ans++;
    }
    cout << ans << endl;
}
