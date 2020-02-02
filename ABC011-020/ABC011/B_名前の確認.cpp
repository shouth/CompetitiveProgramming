#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (auto& e : s) e = tolower(e);
    s[0] = toupper(s[0]);
    cout << s << endl;
}
