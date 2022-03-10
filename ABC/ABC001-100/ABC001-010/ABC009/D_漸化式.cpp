#include<bits/stdc++.h>
using namespace std;

using vec = vector<int64_t>;
using mat = vector<vec>;

mat operator* (const mat &a, const mat &b) {
    int64_t k = a.size();
    mat res(k, vec(k));
    for (int64_t x = 0; x < k; x++) {
        for (int64_t z = 0; z < k; z++) {
            for (int64_t y = 0; y < k; y++) {
                res[x][y] ^= a[x][z] & b[z][y];
            }
        }
    }
    return res;
}

int main() {
    int64_t k, m;
    cin >> k >> m;
    vec a(k);


    mat c(k, vec(k));
    for (auto& e : a) cin >> e;
    for (auto& e : c[0]) cin >> e;
    for (int64_t i = 1; i < k; i++) c[i][i-1] = (1l << 32) - 1;

    if (m <= k) {
        cout << a[m-1] << endl;
        return 0;
    }

    mat b(k, vec(k));
    for (int64_t i = 0; i < k; i++) b[i][i] = (1l << 32) - 1;
    for (int64_t i = m-k; i > 0; i >>= 1) {
        if (i & 1) b = b * c;
        c = c * c;
    }

    int64_t ans = 0;
    for (int64_t i = 0; i < k; i++) ans ^= b[0][i] & a[k-1-i];
    cout << ans << endl;
}
