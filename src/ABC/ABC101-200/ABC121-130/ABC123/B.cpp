#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    vector<int> v(5);
    int last = 0, num = 9;
    for(int i = 0; i < 5; i++) {
        cin >> v[i];
        if (v[i] % 10 != 0 && v[i] % 10 < num) {
            last = i;
            num = v[i] % 10;
        }
    }
    for(int i = 0; i < 5; i++) {
        if(i == last) ans += v[i];
        else ans += v[i] / 10 * 10 + (v[i] % 10 != 0 ? 10 : 0);
    }
    cout << ans << endl;
}