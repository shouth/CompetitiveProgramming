#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    int acc = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        acc += t[i];
    }
    int m;
    cin >> m;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x, p--;
        ans[i] = acc - t[p] + x;
    }
    for (auto& e : ans) cout << e << endl;
}
