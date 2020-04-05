#include<bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        double s, e;
        cin >> s >> e;
        ans += s * e / 10;
    }

    cout << ans << endl;
}
