#include<bits/stdc++.h>
using namespace std;

int main() {
    int h, n;
    cin >> h >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        h -= t;
    }

    cout << (h <= 0 ? "Yes" : "No") << endl;
}
