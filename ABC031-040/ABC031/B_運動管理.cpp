#include<bits/stdc++.h>
using namespace std;

int main() {
    int l, h;
    cin >> l >> h;
    int n;
    cin >> n;
    vector<int> ans(n);
    for (auto& e : ans) {
        int a;
        cin >> a;
        if (a < l) e = l - a;
        else if (h < a) e = -1;
    }
    for (auto& e : ans) cout << e << endl;
}
