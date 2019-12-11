#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k, x, y;
    cin >> n >> k >> x >> y;
    cout << min(n, k) * x + max(n-k, 0l) * y << endl;;
}
