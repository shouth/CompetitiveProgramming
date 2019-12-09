#include<bits/stdc++.h>
using namespace std;

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int u = h, d = 0, l = 0, r = w;
    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a) {
        case 1:
            l = max(l, x);
            break;
        case 2:
            r = min(r, x);
            break;
        case 3:
            d = max(d, y);
            break;
        case 4:
            u = min(u, y);
            break;
        }
    }

    cout << (r-l > 0 && u-d > 0 ? (r-l) * (u-d) : 0) << endl;
}
