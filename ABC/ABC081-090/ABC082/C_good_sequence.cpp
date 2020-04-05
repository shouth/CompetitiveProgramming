#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[ai]++;
    }

    int ans = 0;
    for (auto& e : a) ans += (e.second >= e.first ? e.second - e.first : e.second);
    
    cout << ans << endl;
}
