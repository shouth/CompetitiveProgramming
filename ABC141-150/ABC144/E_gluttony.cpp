#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i64 n, k;
    cin >> n >> k;

    vector<i64> a(n), f(n);
    for (auto& e : a) cin >> e;
    for (auto& e : f) cin >> e;
    sort(begin(a), end(a));
    sort(begin(f), end(f), greater<>());

    i64 l = -1, r = INT64_MAX / 2;
    while (abs(r - l) > 1) {
        i64 mid = (r + l) / 2;

        i64 c = 0;
        for (i32 i = 0; i < n; i++) {
            c += max(0l, a[i] - mid / f[i]);
        }

        (c > k ? l : r) = mid;
    }

    cout << r << endl;
}
