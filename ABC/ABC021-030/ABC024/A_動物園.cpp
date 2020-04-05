#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int s, t;
    cin >> s >> t;
    cout << a * s + b * t - (s + t) * c * (s + t >= k) << endl;
}
