#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d = max({a, b, c}) * 3 - (a + b + c);
    cout << (d % 2 ? d + 3 : d) / 2 << endl;
}
