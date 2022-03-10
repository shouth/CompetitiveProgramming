#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 0, d = i; j < 5; j++) tmp += d % 10, d /= 10;
        if (a <= tmp && tmp <= b) ans += i;
    }

    cout << ans << endl;
}
