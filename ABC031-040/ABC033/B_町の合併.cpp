#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string maxs;
    int tp = 0, maxp = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        cin >> s >> p;
        tp += p;
        if (p > maxp) maxp = p, maxs = s;
    }

    cout << (maxp * 2 > tp ? maxs : "atcoder") << endl;
}
