#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        while (a % 2 == 0 || a % 3 == 2) a--, ans++;
    }

    cout << ans << endl;
}
