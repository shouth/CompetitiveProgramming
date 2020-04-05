#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> m;
    for (int i = 0; i < 3; i++) {
        int n;
        cin >> n;
        m[n]++;
    }
    cout << (m.size() == 2 ? "Yes" : "No") << endl;
}
