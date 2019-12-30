#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    double t = 100.0 / a;
    for (int i = 0; i < 100; i++) {
        t -= (a * t + b * sin(c * t * M_PI) - 100) / (a + b * c * M_PI * cos(c * t * M_PI));
    }

    cout << fixed << setprecision(15) << t << endl;
}
