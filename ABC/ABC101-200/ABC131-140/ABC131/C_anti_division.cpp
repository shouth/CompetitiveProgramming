#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    
    a--;
    int64_t lcd = c * d / __gcd(c, d);
    cout << b - a - (b / c - a / c) - (b / d - a / d) + (b / lcd - a / lcd) << endl;
}
