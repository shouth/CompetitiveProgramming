#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n), b(n);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;

    int ans = 0;
    for (int64_t i = 0; i < 29; i++) {
        vector<int> mb(n);
        transform(begin(b), end(b), begin(mb), [&](auto e) { return e % (1l << (i + 1)); });
        sort(begin(mb), end(mb));

        int64_t cnt = 0;
        for (auto& e : a) {
            int64_t ma = e % (1l << (i + 1));
            auto flitr = lower_bound(begin(mb), end(mb), (1l << i) - ma);
            auto fritr = lower_bound(begin(mb), end(mb), 2l * (1l << i) - ma);
            auto slitr = lower_bound(begin(mb), end(mb), 3l * (1l << i) - ma);
            auto sritr = lower_bound(begin(mb), end(mb), 4l * (1l << i) - ma);
            cnt += ((fritr - flitr) + (sritr - slitr));
        }

        ans += (cnt % 2) << i;
    }

    cout << ans << endl;
}
