#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, q;
    cin >> a >> b >> q;
    vector<int64_t> s(a+2), t(b+2), ans(q, 1e18);
    for (int i=1; i<=a; i++) cin >> s[i];
    s[0] = -1e18;
    s[a+1] = 1e18;
    for (int i=1; i<=b; i++) cin >> t[i];
    t[0] = -1e18;
    t[b+1] = 1e18;
    for (auto& e : ans) {
        int64_t n;
        cin >> n;
        auto rs = upper_bound(s.begin(), s.end(), n), rt = upper_bound(t.begin(), t.end(), n);

        for (auto& ss : { rs, rs - 1 }) {
            for (auto& tt : { rt, rt - 1 }) {
                e = min(e, abs(*ss - n) + abs(*tt - *ss));
                e = min(e, abs(*tt - n) + abs(*ss - *tt));
            }
        }
    }

    for(auto& e : ans) cout << e << endl;
}