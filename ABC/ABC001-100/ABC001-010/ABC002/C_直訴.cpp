#include<bits/stdc++.h>
using namespace std;

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa, yb -= ya, xc -= xa, yc -= ya;
    cout << fixed << setprecision(5) << abs(xb*yc - xc*yb) / 2.0 << endl;
}
