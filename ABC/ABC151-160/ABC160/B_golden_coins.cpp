#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i64 x;
    cin >> x;
    cout << x / 500 * 1000 + x % 500 / 5 * 5 << endl;
}
