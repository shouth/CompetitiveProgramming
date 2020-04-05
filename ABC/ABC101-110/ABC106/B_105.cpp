#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        int num = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) num++;
        }
        if (num == 8) ans++;
    }

    cout << ans << endl;
}
