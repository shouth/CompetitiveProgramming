#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t = 0, d = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0) t += a, d++;
    }

    cout << (t + d - 1) / d << endl;
}
