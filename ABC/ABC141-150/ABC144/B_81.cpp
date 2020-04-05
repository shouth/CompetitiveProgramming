#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans = "No";
    for (int i = 1; i <= 9; i++) {
        if (n % i == 0 && n / i < 10) ans = "Yes";
    }

    cout << ans << endl;
}
