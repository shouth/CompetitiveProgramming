#include<bits/stdc++.h>
using namespace std;

using i32 = int_fast32_t;
using i64 = int_fast64_t;

int main() {
    i32 n;
    cin >> n;
    string s;
    cin >> s;
    
    i32 ans = 0;
    for (i32 l = 0; l < n; l++) {
        i32 m = n-l;
        vector<i32> z(m);
        z[0] = m;

        for (i32 i = 1, j = 0; i < m;) {
            while (i+j < m && s[l+j] == s[l+i+j]) j++;
            z[i] = j;

            if (j == 0) {
                i++;
                continue;
            }

            i32 k = 1;
            while (k < j && k+z[k] < j) {
                z[i+k] = z[k];
                k++;
            }

            i += k, j -= k;
        }

        for (i32 i = 1; i < m; i++) {
            if (z[i] <= i) ans = max(ans, z[i]);
        }
    }

    cout << ans << endl;
}
