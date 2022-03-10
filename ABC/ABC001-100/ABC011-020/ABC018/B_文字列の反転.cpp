#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r, l--;
        reverse(begin(s) + l, begin(s) + r);
    }

    cout << s << endl;
}
