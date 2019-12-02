#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    replace(begin(s), end(s), ',', ' ');
    cout << s << endl;
}
