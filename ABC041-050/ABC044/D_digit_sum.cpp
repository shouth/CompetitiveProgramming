#include<bits/stdc++.h>
using namespace std;

constexpr int64_t INF = 1e18;

constexpr int64_t f(int64_t b, int64_t n) {
    return n < b ? n : f(b, n / b) + n % b;
}

int main() {
    int64_t n, s;
    cin >> n >> s;

    int64_t ans = INF;
    if (n == s) ans = n + 1;

    for (int64_t b = 2; b <= sqrt(n); b++) {
        if (f(b, n) == s) ans = min(ans, b);
    }

    for (int64_t p = 1; p < sqrt(n); p++) {
        int64_t b = (n - s) / p + 1;
        if (b <= 1) continue;
        if (f(b, n) == s) ans = min(ans, b);
    }

    cout << (ans != INF ? ans : -1) << endl;
}
