#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b;
    cin >> a >> b;
    if ((a + b) & 1) cout << "IMPOSSIBLE" << endl;
    else cout << (a + b) / 2 << endl;
}
