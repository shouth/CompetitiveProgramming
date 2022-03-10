#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    map<char, int> c;
    for (auto& e : s) c[e]++;
    for (char i = 'A'; i != 'G'; i++) cout << c[i] << (i != 'F' ? " " : "");
    cout << endl;
}
