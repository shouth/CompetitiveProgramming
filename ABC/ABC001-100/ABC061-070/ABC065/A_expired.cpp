#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, a, b;
    cin >> x >> a >> b;
    cout << (b-a <= 0 ? "delicious" : b-a <= x ? "safe" : "dangerous") << endl;
}
