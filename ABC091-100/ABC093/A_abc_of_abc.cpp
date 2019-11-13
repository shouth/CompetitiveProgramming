#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(begin(s), end(s));
    cout << (s == "abc" ? "Yes" : "No") << endl;
}
