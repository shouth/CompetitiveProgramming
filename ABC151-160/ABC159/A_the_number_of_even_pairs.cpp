#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, m;
    cin >> n >> m;
    cout << (n * (n-1)) / 2 + (m * (m-1)) / 2 << endl;
}
