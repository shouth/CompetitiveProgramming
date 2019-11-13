#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max({a, b, c}) * 10 + a + b + c - max({a, b, c}) << endl;
}
