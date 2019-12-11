#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans;
    for (auto& e : s) {
        if (e == 'B') {
            if (!ans.empty()) ans.pop_back();
        } else {
            ans += e;
        }
    }
    cout << ans << endl;
}
