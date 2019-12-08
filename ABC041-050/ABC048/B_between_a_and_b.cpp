#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, x;
    cin >> a >> b >> x;
    cout << b / x - a / x + (a % x == 0) << endl;
}
