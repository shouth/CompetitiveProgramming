#include<bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    
    int ans = 1;
    for (int i = 2; i <= sqrt(x); i++) {
        int can = 1;
        while (can * i <= x) can *= i;
        ans = max(ans, can);
    }

    cout << ans << endl;
}
