#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int64_t> lr(n+1, 0);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        lr[l]++, lr[r+1]--;
    }

    for (int i = 0; i < n; i++) {
        lr[i+1] += lr[i];
    }

    cout << count(lr.begin(), lr.end(), m) << endl;
}
