#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b;
    cin >> a >> b;

    int64_t n = __gcd(a, b);
    map<int64_t, int64_t> fans;
    fans[1]++;
    for (int64_t m = 2, lim = sqrt(n) + 2; m < lim; m++) {
        while (n % m == 0) {
            fans[m]++;
            n /= m;
        }
    }

    if (n > 1) fans[n]++;

    cout << fans.size() << endl;
}
