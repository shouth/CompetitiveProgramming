#include<bits/stdc++.h>
using namespace std;

constexpr int64_t MOD = 1e9 + 7;

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;
    cout << a * b % MOD * c % MOD << endl;
}
