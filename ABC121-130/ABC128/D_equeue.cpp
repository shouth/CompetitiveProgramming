#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), acc(n+1);

    for (auto& e : v) cin >> e;
    for (int i=0; i<n; i++) acc[i+1] = acc[i] + v[i];

    int limit = min(n, k);
    int64_t ans = 0;
    for (int left = 0; left <= limit; left++) {
        for (int right = 0; left + right <= limit; right++) {
            int64_t can = acc[left] + acc[n] - acc[n - right];

            vector<int> tmp(left + right);
            copy_n(v.begin(), left, tmp.begin());
            copy_n(v.rbegin(), right, tmp.rbegin());
            sort(tmp.begin(), tmp.end());
            auto itr = min(lower_bound(tmp.begin(), tmp.end(), 0), tmp.begin() + (k - left - right));
            can -= accumulate(tmp.begin(), itr, 0);
            ans = max(ans, can);
        }
    }

    cout << ans << endl;
}
