#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = 0, num = 1;
    while (num < b) {
        num += a - 1;
        ans++;
    }

    cout << ans << endl;
}
