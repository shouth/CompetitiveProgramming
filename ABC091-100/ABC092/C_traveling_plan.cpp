#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> acc(n+2);
    for (int i = 0; i + 1 < n + 2; i++) acc[i+1] = acc[i] + abs(a[i+1] - a[i]);

    for (int i = 1; i <= n; i++) {
        cout << acc[i-1] + (acc[n+1] - acc[i+1]) + abs(a[i+1] - a[i-1]) << endl;
    }
}
