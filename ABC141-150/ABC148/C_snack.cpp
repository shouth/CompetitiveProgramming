#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b;
    cin >> a >> b;
    cout << a * b / __gcd(a, b) << endl;
}
