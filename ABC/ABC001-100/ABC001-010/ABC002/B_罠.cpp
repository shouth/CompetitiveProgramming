#include<bits/stdc++.h>
using namespace std;

int main() {
    string w;
    cin >> w;
    string ans, aiueo = "aiueo";
    for (auto& e : w) {
        if (aiueo.find(e) == string::npos) ans += e;
    }
    cout << ans << endl;
}
