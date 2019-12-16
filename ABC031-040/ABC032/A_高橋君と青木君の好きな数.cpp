#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int ablcm = a * b / __gcd(a, b);
    int ans = ablcm;
    while (ans < n) ans += ablcm;
    cout << ans << endl;
}
