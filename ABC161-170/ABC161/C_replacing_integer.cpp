#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i64 n, k;
    cin >> n >> k, n %= k;
    cout << min(n, abs(k - n)) << endl;
}
