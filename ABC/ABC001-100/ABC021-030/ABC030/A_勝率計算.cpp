#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (c*b == a*d ? "DRAW" : c*b > a*d ? "TAKAHASHI" : "AOKI") << endl;
}
