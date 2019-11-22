#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;

    int64_t ans = 20;
    for (int i = 1; i <= sqrt(n)+1; i++) {
        if (n % i == 0) ans = min(ans, (int64_t) max(log10(i), log10(n / i)));
    }
    cout << ans + 1 << endl;
}
