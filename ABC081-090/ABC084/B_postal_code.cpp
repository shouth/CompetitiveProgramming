#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool h = s[a] == '-';
    s.erase(begin(s) + a);
    bool n = all_of(begin(s), end(s), ::isdigit);
    cout << (h && n ? "Yes" : "No") << endl;
}
