#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c;
    d = b / a;
    cout << (d > c ? c : d) << endl;
}