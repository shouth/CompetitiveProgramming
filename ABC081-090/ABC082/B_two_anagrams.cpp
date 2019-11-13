#include<bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    sort(begin(s), end(s));
    sort(begin(t), end(t), greater<>());
    cout << (s < t ? "Yes" : "No") << endl;
    
}
