#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d = 0;
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != i) d++;
    }

    cout << (d <= 2 ? "YES" : "NO") << endl;
}
