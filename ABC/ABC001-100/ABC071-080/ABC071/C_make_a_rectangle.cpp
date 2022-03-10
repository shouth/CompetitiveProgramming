#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    map<int64_t, int64_t, greater<int64_t>> m { { 0, 0 } };
    for (int64_t i = 0; i < n; i++) {
        int64_t a;
        cin >> a;
        m[a]++;
    }
    int64_t ans = 0;
    auto f = [](auto e) { return e.second > 1; };
    auto e1 = find_if(begin(m), end(m), f);
    if (e1 != end(m)) {
        if (e1->second > 3) {
            ans = e1->first * e1->first;
        } else {
            auto e2 = find_if(next(e1), end(m), f);
            if (e2 != end(m) && e2->second > 1) {
                ans = e1->first * e2->first;
            }
        }
    }
    cout << ans << endl;
}
