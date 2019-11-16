#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> m;
    int ansl = 0, ansm = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (3200 <= a) ansm++;
        else if (++m[a / 400] == 1) ansl++;
    }
    cout << (!ansl ? 1 : ansl) << " " << ansl + ansm << endl;
}
