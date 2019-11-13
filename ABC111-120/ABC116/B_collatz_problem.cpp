#include<bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cin >> s;
    vector<bool> v(1'000'000, false);
    int ans = 1;
    for (int a = s; !v[a]; v[a] = true, a = a&1 ? 3*a+1 : a/2, ans++);
    cout << ans << endl;
}
