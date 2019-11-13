#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    vector<int64_t> a(n+1);
    for (int64_t i = 1; i <= n; i++) cin >> a[i];
    for (int64_t i = 0; i + 1 <= n; i++) a[i+1] += a[i];

    int64_t ans = 1e18;
    for (auto itr = begin(a) + 2; itr != end(a) - 2; itr++) {
        auto lh = lower_bound(begin(a), itr + 1, *itr / 2);
        auto gh = lower_bound(itr + 1, end(a), (*itr + a.back()) / 2);

        for (auto& litr : { lh, lh - 1 }) {
            for (auto& gitr : { gh, gh - 1 }) {
                vector<int64_t> pqrs{*litr, *itr - *litr, *gitr - *itr, a.back() - *gitr};
                ans = min(ans, *max_element(begin(pqrs), end(pqrs)) - *min_element(begin(pqrs), end(pqrs)));
            }
        }
    }

    cout << ans << endl;
}
