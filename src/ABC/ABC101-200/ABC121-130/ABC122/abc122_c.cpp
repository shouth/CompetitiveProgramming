#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n >> q >> s;

    vector<int> ac(100500), lr(100500);
    for(size_t i = 1, count = 0; i < n; i++) {
        if(s[i-1] == 'A' && s[i] == 'C') count++;
        ac[i] = count;
    }

    for(size_t i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        lr[i] = ac[r-1] - ac[l-1];
    }

    for(size_t i = 0; i < q; i++) {
        cout << lr[i] << endl;
    }
}