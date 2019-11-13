#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    for (auto& e : a) cin >> e;
    vector<int64_t> f(n);
    for (auto& e : a) cin >> e;

    sort(begin(a), end(a), greater<>());
    sort(begin(f), end(f));

    vector<int64_t> laacc(n), raacc(n);
    partial_sum(begin(a), end(a), begin(laacc));
    partial_sum(rbegin(a), rend(a), begin(raacc));

    int64_t ans = 1e18;
    if (raacc[0] < k) {
        int64_t bottom = 0, top = lower_bound(begin(laacc), end(laacc), k) - begin(laacc);

        
        while (bottom <= top) {
            int64_t middle = bottom + (top - bottom) / 2;
            
        }
    } else {
        ans = 0;
    }

    cout << ans << endl;
}
