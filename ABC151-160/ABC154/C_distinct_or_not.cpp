#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> c;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[a]++;
    }
    string ans = "YES";
    for (auto& e : c) {
        if (e.second != 1) ans = "NO";
    }

    cout << ans << endl;
}
