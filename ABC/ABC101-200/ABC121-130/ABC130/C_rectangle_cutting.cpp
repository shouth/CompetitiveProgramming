#include<bits/stdc++.h>
using namespace std;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    cout << w*h/2 << " " << (w/2 == x && h/2 == y) << endl;
}
