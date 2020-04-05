#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    double t = abs(30*(n%12 + m/60.0) - 6*m);
    cout << min(t, 360 - t) << endl;
}
