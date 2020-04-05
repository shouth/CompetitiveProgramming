#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n, k;
    cin >> n >> k;
    
    i32 m = n-1;
    i32 l = (n-1) * (n-2) / 2;
    if (k > l) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<i32>> g(n);
    for (i32 i = 1; i < n; i++) {
        g[0].push_back(i);
    }

    for (i32 i = 1; i < n; i++) {
        for (i32 j = i+1; j < n; j++) {
            if (l == k) break;
            g[i].push_back(j);
            m++, l--;
        }
    }

    cout << m << endl;
    for (i32 i = 0; i < n; i++) {
        for (auto& e : g[i]) {
            cout << i+1 << " " << e+1 << endl;
        }
    }
}
