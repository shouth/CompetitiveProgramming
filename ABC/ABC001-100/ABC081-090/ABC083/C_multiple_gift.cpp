#include<bits/stdc++.h>
using namespace std;

int main() {
    uint64_t x, y;
    cin >> x >> y;
    uint64_t ans = 0;
    while (x <= y) x <<= 1u, ans++;
    cout << ans << endl;
}
