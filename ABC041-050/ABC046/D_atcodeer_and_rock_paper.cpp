#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s.size() / 2 - count(begin(s), end(s), 'p') << endl;
}
