#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t n;
    cin >> n;
    map<char, int64_t> m;
    for (int64_t i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s[0]]++;
    }

    int64_t ans = 0;
    string march = "MARCH";
    for (int64_t i = 0; i + 2 < 5; i++) {
        for (int64_t j = i + 1; j + 1 < 5; j++) {
            for (int64_t k = j + 1; k < 5; k++) {
                ans += m[march[i]] * m[march[j]] * m[march[k]];
            }
        }
    }

    cout << ans << endl;
}
