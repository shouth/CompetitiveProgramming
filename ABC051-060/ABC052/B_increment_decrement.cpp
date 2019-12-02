#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c = 0, ans = 0;
    for (auto& e : s) {
        ans = max(ans, c += (e == 'I' ? 1 : -1));
    }
    cout << ans << endl;
}
