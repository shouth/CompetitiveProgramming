#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 0; i < 4; i++) {
        if ((n >> i) & 1) ans.push_back(1 << i);
    }
    cout << ans.size() << endl;
    for (auto& e : ans) cout << e << endl; 
}
