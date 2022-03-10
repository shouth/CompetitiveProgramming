#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, h;
    cin >> n >> h;
    vector<int64_t> a(n), b(n);
    for (int64_t i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(begin(a), end(a), greater<>());
    sort(begin(b), end(b), greater<>());
    auto itr = upper_bound(begin(b), end(b), a[0], greater<>());
    partial_sum(begin(b), itr, begin(b));
    auto bor = lower_bound(begin(b), itr, h);
    if (bor == itr) bor--;
    int64_t ans = bor - begin(b) + 1l + (max(0l, h - *bor) + a[0] - 1l) / a[0];
    cout << ans << endl;
}
