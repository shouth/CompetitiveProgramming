#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string ans = "!";
    if (a + b == c) ans = a == 0 || b == 0 ? "?" : "+";
    if (a - b == c) ans = a == 0 || b == 0 ? "?" : "-";
    cout << ans << endl;
}
