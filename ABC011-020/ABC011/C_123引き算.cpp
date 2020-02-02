#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ng1, ng2, ng3;
    cin >> ng1 >> ng2 >> ng3;
    vector<int> r(n+1, -1);
    if (n != ng1 && n != ng2 && n != ng3) r[n] = 100;
    for (int x = n; x >= 0; x--) {
        if (r[x] < 1) continue;
        for (int y = x; x - y <= 3 && y >= 0; y--) {
            if (y >= 0 && y != ng1 && y != ng2 && y != ng3) r[y] = max(r[y], r[x] - 1);
        }
    }

    cout << (r[0] != -1 ? "YES" : "NO") << endl;
}
